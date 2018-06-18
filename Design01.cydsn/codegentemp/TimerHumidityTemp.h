/*******************************************************************************
* File Name: TimerHumidityTemp.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the TimerHumidityTemp
*  component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_TCPWM_TimerHumidityTemp_H)
#define CY_TCPWM_TimerHumidityTemp_H


#include "CyLib.h"
#include "cytypes.h"
#include "cyfitter.h"


/*******************************************************************************
* Internal Type defines
*******************************************************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} TimerHumidityTemp_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  TimerHumidityTemp_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define TimerHumidityTemp_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define TimerHumidityTemp_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define TimerHumidityTemp_CONFIG                         (1lu)

/* Quad Mode */
/* Parameters */
#define TimerHumidityTemp_QUAD_ENCODING_MODES            (0lu)
#define TimerHumidityTemp_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define TimerHumidityTemp_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define TimerHumidityTemp_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define TimerHumidityTemp_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define TimerHumidityTemp_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define TimerHumidityTemp_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define TimerHumidityTemp_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define TimerHumidityTemp_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define TimerHumidityTemp_TC_RUN_MODE                    (0lu)
#define TimerHumidityTemp_TC_COUNTER_MODE                (0lu)
#define TimerHumidityTemp_TC_COMP_CAP_MODE               (2lu)
#define TimerHumidityTemp_TC_PRESCALER                   (0lu)

/* Signal modes */
#define TimerHumidityTemp_TC_RELOAD_SIGNAL_MODE          (0lu)
#define TimerHumidityTemp_TC_COUNT_SIGNAL_MODE           (3lu)
#define TimerHumidityTemp_TC_START_SIGNAL_MODE           (0lu)
#define TimerHumidityTemp_TC_STOP_SIGNAL_MODE            (0lu)
#define TimerHumidityTemp_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define TimerHumidityTemp_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define TimerHumidityTemp_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define TimerHumidityTemp_TC_START_SIGNAL_PRESENT        (0lu)
#define TimerHumidityTemp_TC_STOP_SIGNAL_PRESENT         (0lu)
#define TimerHumidityTemp_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define TimerHumidityTemp_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define TimerHumidityTemp_PWM_KILL_EVENT                 (0lu)
#define TimerHumidityTemp_PWM_STOP_EVENT                 (0lu)
#define TimerHumidityTemp_PWM_MODE                       (4lu)
#define TimerHumidityTemp_PWM_OUT_N_INVERT               (0lu)
#define TimerHumidityTemp_PWM_OUT_INVERT                 (0lu)
#define TimerHumidityTemp_PWM_ALIGN                      (0lu)
#define TimerHumidityTemp_PWM_RUN_MODE                   (0lu)
#define TimerHumidityTemp_PWM_DEAD_TIME_CYCLE            (0lu)
#define TimerHumidityTemp_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define TimerHumidityTemp_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define TimerHumidityTemp_PWM_COUNT_SIGNAL_MODE          (3lu)
#define TimerHumidityTemp_PWM_START_SIGNAL_MODE          (0lu)
#define TimerHumidityTemp_PWM_STOP_SIGNAL_MODE           (0lu)
#define TimerHumidityTemp_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define TimerHumidityTemp_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define TimerHumidityTemp_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define TimerHumidityTemp_PWM_START_SIGNAL_PRESENT       (0lu)
#define TimerHumidityTemp_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define TimerHumidityTemp_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define TimerHumidityTemp_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define TimerHumidityTemp_TC_PERIOD_VALUE                (999lu)
#define TimerHumidityTemp_TC_COMPARE_VALUE               (65535lu)
#define TimerHumidityTemp_TC_COMPARE_BUF_VALUE           (65535lu)
#define TimerHumidityTemp_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define TimerHumidityTemp_PWM_PERIOD_VALUE               (65535lu)
#define TimerHumidityTemp_PWM_PERIOD_BUF_VALUE           (65535lu)
#define TimerHumidityTemp_PWM_PERIOD_SWAP                (0lu)
#define TimerHumidityTemp_PWM_COMPARE_VALUE              (65535lu)
#define TimerHumidityTemp_PWM_COMPARE_BUF_VALUE          (65535lu)
#define TimerHumidityTemp_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define TimerHumidityTemp__LEFT 0
#define TimerHumidityTemp__RIGHT 1
#define TimerHumidityTemp__CENTER 2
#define TimerHumidityTemp__ASYMMETRIC 3

#define TimerHumidityTemp__X1 0
#define TimerHumidityTemp__X2 1
#define TimerHumidityTemp__X4 2

#define TimerHumidityTemp__PWM 4
#define TimerHumidityTemp__PWM_DT 5
#define TimerHumidityTemp__PWM_PR 6

#define TimerHumidityTemp__INVERSE 1
#define TimerHumidityTemp__DIRECT 0

#define TimerHumidityTemp__CAPTURE 2
#define TimerHumidityTemp__COMPARE 0

#define TimerHumidityTemp__TRIG_LEVEL 3
#define TimerHumidityTemp__TRIG_RISING 0
#define TimerHumidityTemp__TRIG_FALLING 1
#define TimerHumidityTemp__TRIG_BOTH 2

#define TimerHumidityTemp__INTR_MASK_TC 1
#define TimerHumidityTemp__INTR_MASK_CC_MATCH 2
#define TimerHumidityTemp__INTR_MASK_NONE 0
#define TimerHumidityTemp__INTR_MASK_TC_CC 3

#define TimerHumidityTemp__UNCONFIG 8
#define TimerHumidityTemp__TIMER 1
#define TimerHumidityTemp__QUAD 3
#define TimerHumidityTemp__PWM_SEL 7

#define TimerHumidityTemp__COUNT_UP 0
#define TimerHumidityTemp__COUNT_DOWN 1
#define TimerHumidityTemp__COUNT_UPDOWN0 2
#define TimerHumidityTemp__COUNT_UPDOWN1 3


/* Prescaler */
#define TimerHumidityTemp_PRESCALE_DIVBY1                ((uint32)(0u << TimerHumidityTemp_PRESCALER_SHIFT))
#define TimerHumidityTemp_PRESCALE_DIVBY2                ((uint32)(1u << TimerHumidityTemp_PRESCALER_SHIFT))
#define TimerHumidityTemp_PRESCALE_DIVBY4                ((uint32)(2u << TimerHumidityTemp_PRESCALER_SHIFT))
#define TimerHumidityTemp_PRESCALE_DIVBY8                ((uint32)(3u << TimerHumidityTemp_PRESCALER_SHIFT))
#define TimerHumidityTemp_PRESCALE_DIVBY16               ((uint32)(4u << TimerHumidityTemp_PRESCALER_SHIFT))
#define TimerHumidityTemp_PRESCALE_DIVBY32               ((uint32)(5u << TimerHumidityTemp_PRESCALER_SHIFT))
#define TimerHumidityTemp_PRESCALE_DIVBY64               ((uint32)(6u << TimerHumidityTemp_PRESCALER_SHIFT))
#define TimerHumidityTemp_PRESCALE_DIVBY128              ((uint32)(7u << TimerHumidityTemp_PRESCALER_SHIFT))

/* TCPWM set modes */
#define TimerHumidityTemp_MODE_TIMER_COMPARE             ((uint32)(TimerHumidityTemp__COMPARE         <<  \
                                                                  TimerHumidityTemp_MODE_SHIFT))
#define TimerHumidityTemp_MODE_TIMER_CAPTURE             ((uint32)(TimerHumidityTemp__CAPTURE         <<  \
                                                                  TimerHumidityTemp_MODE_SHIFT))
#define TimerHumidityTemp_MODE_QUAD                      ((uint32)(TimerHumidityTemp__QUAD            <<  \
                                                                  TimerHumidityTemp_MODE_SHIFT))
#define TimerHumidityTemp_MODE_PWM                       ((uint32)(TimerHumidityTemp__PWM             <<  \
                                                                  TimerHumidityTemp_MODE_SHIFT))
#define TimerHumidityTemp_MODE_PWM_DT                    ((uint32)(TimerHumidityTemp__PWM_DT          <<  \
                                                                  TimerHumidityTemp_MODE_SHIFT))
#define TimerHumidityTemp_MODE_PWM_PR                    ((uint32)(TimerHumidityTemp__PWM_PR          <<  \
                                                                  TimerHumidityTemp_MODE_SHIFT))

/* Quad Modes */
#define TimerHumidityTemp_MODE_X1                        ((uint32)(TimerHumidityTemp__X1              <<  \
                                                                  TimerHumidityTemp_QUAD_MODE_SHIFT))
#define TimerHumidityTemp_MODE_X2                        ((uint32)(TimerHumidityTemp__X2              <<  \
                                                                  TimerHumidityTemp_QUAD_MODE_SHIFT))
#define TimerHumidityTemp_MODE_X4                        ((uint32)(TimerHumidityTemp__X4              <<  \
                                                                  TimerHumidityTemp_QUAD_MODE_SHIFT))

/* Counter modes */
#define TimerHumidityTemp_COUNT_UP                       ((uint32)(TimerHumidityTemp__COUNT_UP        <<  \
                                                                  TimerHumidityTemp_UPDOWN_SHIFT))
#define TimerHumidityTemp_COUNT_DOWN                     ((uint32)(TimerHumidityTemp__COUNT_DOWN      <<  \
                                                                  TimerHumidityTemp_UPDOWN_SHIFT))
#define TimerHumidityTemp_COUNT_UPDOWN0                  ((uint32)(TimerHumidityTemp__COUNT_UPDOWN0   <<  \
                                                                  TimerHumidityTemp_UPDOWN_SHIFT))
#define TimerHumidityTemp_COUNT_UPDOWN1                  ((uint32)(TimerHumidityTemp__COUNT_UPDOWN1   <<  \
                                                                  TimerHumidityTemp_UPDOWN_SHIFT))

/* PWM output invert */
#define TimerHumidityTemp_INVERT_LINE                    ((uint32)(TimerHumidityTemp__INVERSE         <<  \
                                                                  TimerHumidityTemp_INV_OUT_SHIFT))
#define TimerHumidityTemp_INVERT_LINE_N                  ((uint32)(TimerHumidityTemp__INVERSE         <<  \
                                                                  TimerHumidityTemp_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define TimerHumidityTemp_TRIG_RISING                    ((uint32)TimerHumidityTemp__TRIG_RISING)
#define TimerHumidityTemp_TRIG_FALLING                   ((uint32)TimerHumidityTemp__TRIG_FALLING)
#define TimerHumidityTemp_TRIG_BOTH                      ((uint32)TimerHumidityTemp__TRIG_BOTH)
#define TimerHumidityTemp_TRIG_LEVEL                     ((uint32)TimerHumidityTemp__TRIG_LEVEL)

/* Interrupt mask */
#define TimerHumidityTemp_INTR_MASK_TC                   ((uint32)TimerHumidityTemp__INTR_MASK_TC)
#define TimerHumidityTemp_INTR_MASK_CC_MATCH             ((uint32)TimerHumidityTemp__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define TimerHumidityTemp_CC_MATCH_SET                   (0x00u)
#define TimerHumidityTemp_CC_MATCH_CLEAR                 (0x01u)
#define TimerHumidityTemp_CC_MATCH_INVERT                (0x02u)
#define TimerHumidityTemp_CC_MATCH_NO_CHANGE             (0x03u)
#define TimerHumidityTemp_OVERLOW_SET                    (0x00u)
#define TimerHumidityTemp_OVERLOW_CLEAR                  (0x04u)
#define TimerHumidityTemp_OVERLOW_INVERT                 (0x08u)
#define TimerHumidityTemp_OVERLOW_NO_CHANGE              (0x0Cu)
#define TimerHumidityTemp_UNDERFLOW_SET                  (0x00u)
#define TimerHumidityTemp_UNDERFLOW_CLEAR                (0x10u)
#define TimerHumidityTemp_UNDERFLOW_INVERT               (0x20u)
#define TimerHumidityTemp_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define TimerHumidityTemp_PWM_MODE_LEFT                  (TimerHumidityTemp_CC_MATCH_CLEAR        |   \
                                                         TimerHumidityTemp_OVERLOW_SET           |   \
                                                         TimerHumidityTemp_UNDERFLOW_NO_CHANGE)
#define TimerHumidityTemp_PWM_MODE_RIGHT                 (TimerHumidityTemp_CC_MATCH_SET          |   \
                                                         TimerHumidityTemp_OVERLOW_NO_CHANGE     |   \
                                                         TimerHumidityTemp_UNDERFLOW_CLEAR)
#define TimerHumidityTemp_PWM_MODE_ASYM                  (TimerHumidityTemp_CC_MATCH_INVERT       |   \
                                                         TimerHumidityTemp_OVERLOW_SET           |   \
                                                         TimerHumidityTemp_UNDERFLOW_CLEAR)

#if (TimerHumidityTemp_CY_TCPWM_V2)
    #if(TimerHumidityTemp_CY_TCPWM_4000)
        #define TimerHumidityTemp_PWM_MODE_CENTER                (TimerHumidityTemp_CC_MATCH_INVERT       |   \
                                                                 TimerHumidityTemp_OVERLOW_NO_CHANGE     |   \
                                                                 TimerHumidityTemp_UNDERFLOW_CLEAR)
    #else
        #define TimerHumidityTemp_PWM_MODE_CENTER                (TimerHumidityTemp_CC_MATCH_INVERT       |   \
                                                                 TimerHumidityTemp_OVERLOW_SET           |   \
                                                                 TimerHumidityTemp_UNDERFLOW_CLEAR)
    #endif /* (TimerHumidityTemp_CY_TCPWM_4000) */
#else
    #define TimerHumidityTemp_PWM_MODE_CENTER                (TimerHumidityTemp_CC_MATCH_INVERT       |   \
                                                             TimerHumidityTemp_OVERLOW_NO_CHANGE     |   \
                                                             TimerHumidityTemp_UNDERFLOW_CLEAR)
#endif /* (TimerHumidityTemp_CY_TCPWM_NEW) */

/* Command operations without condition */
#define TimerHumidityTemp_CMD_CAPTURE                    (0u)
#define TimerHumidityTemp_CMD_RELOAD                     (8u)
#define TimerHumidityTemp_CMD_STOP                       (16u)
#define TimerHumidityTemp_CMD_START                      (24u)

/* Status */
#define TimerHumidityTemp_STATUS_DOWN                    (1u)
#define TimerHumidityTemp_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   TimerHumidityTemp_Init(void);
void   TimerHumidityTemp_Enable(void);
void   TimerHumidityTemp_Start(void);
void   TimerHumidityTemp_Stop(void);

void   TimerHumidityTemp_SetMode(uint32 mode);
void   TimerHumidityTemp_SetCounterMode(uint32 counterMode);
void   TimerHumidityTemp_SetPWMMode(uint32 modeMask);
void   TimerHumidityTemp_SetQDMode(uint32 qdMode);

void   TimerHumidityTemp_SetPrescaler(uint32 prescaler);
void   TimerHumidityTemp_TriggerCommand(uint32 mask, uint32 command);
void   TimerHumidityTemp_SetOneShot(uint32 oneShotEnable);
uint32 TimerHumidityTemp_ReadStatus(void);

void   TimerHumidityTemp_SetPWMSyncKill(uint32 syncKillEnable);
void   TimerHumidityTemp_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   TimerHumidityTemp_SetPWMDeadTime(uint32 deadTime);
void   TimerHumidityTemp_SetPWMInvert(uint32 mask);

void   TimerHumidityTemp_SetInterruptMode(uint32 interruptMask);
uint32 TimerHumidityTemp_GetInterruptSourceMasked(void);
uint32 TimerHumidityTemp_GetInterruptSource(void);
void   TimerHumidityTemp_ClearInterrupt(uint32 interruptMask);
void   TimerHumidityTemp_SetInterrupt(uint32 interruptMask);

void   TimerHumidityTemp_WriteCounter(uint32 count);
uint32 TimerHumidityTemp_ReadCounter(void);

uint32 TimerHumidityTemp_ReadCapture(void);
uint32 TimerHumidityTemp_ReadCaptureBuf(void);

void   TimerHumidityTemp_WritePeriod(uint32 period);
uint32 TimerHumidityTemp_ReadPeriod(void);
void   TimerHumidityTemp_WritePeriodBuf(uint32 periodBuf);
uint32 TimerHumidityTemp_ReadPeriodBuf(void);

void   TimerHumidityTemp_WriteCompare(uint32 compare);
uint32 TimerHumidityTemp_ReadCompare(void);
void   TimerHumidityTemp_WriteCompareBuf(uint32 compareBuf);
uint32 TimerHumidityTemp_ReadCompareBuf(void);

void   TimerHumidityTemp_SetPeriodSwap(uint32 swapEnable);
void   TimerHumidityTemp_SetCompareSwap(uint32 swapEnable);

void   TimerHumidityTemp_SetCaptureMode(uint32 triggerMode);
void   TimerHumidityTemp_SetReloadMode(uint32 triggerMode);
void   TimerHumidityTemp_SetStartMode(uint32 triggerMode);
void   TimerHumidityTemp_SetStopMode(uint32 triggerMode);
void   TimerHumidityTemp_SetCountMode(uint32 triggerMode);

void   TimerHumidityTemp_SaveConfig(void);
void   TimerHumidityTemp_RestoreConfig(void);
void   TimerHumidityTemp_Sleep(void);
void   TimerHumidityTemp_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define TimerHumidityTemp_BLOCK_CONTROL_REG              (*(reg32 *) TimerHumidityTemp_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define TimerHumidityTemp_BLOCK_CONTROL_PTR              ( (reg32 *) TimerHumidityTemp_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define TimerHumidityTemp_COMMAND_REG                    (*(reg32 *) TimerHumidityTemp_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define TimerHumidityTemp_COMMAND_PTR                    ( (reg32 *) TimerHumidityTemp_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define TimerHumidityTemp_INTRRUPT_CAUSE_REG             (*(reg32 *) TimerHumidityTemp_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define TimerHumidityTemp_INTRRUPT_CAUSE_PTR             ( (reg32 *) TimerHumidityTemp_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define TimerHumidityTemp_CONTROL_REG                    (*(reg32 *) TimerHumidityTemp_cy_m0s8_tcpwm_1__CTRL )
#define TimerHumidityTemp_CONTROL_PTR                    ( (reg32 *) TimerHumidityTemp_cy_m0s8_tcpwm_1__CTRL )
#define TimerHumidityTemp_STATUS_REG                     (*(reg32 *) TimerHumidityTemp_cy_m0s8_tcpwm_1__STATUS )
#define TimerHumidityTemp_STATUS_PTR                     ( (reg32 *) TimerHumidityTemp_cy_m0s8_tcpwm_1__STATUS )
#define TimerHumidityTemp_COUNTER_REG                    (*(reg32 *) TimerHumidityTemp_cy_m0s8_tcpwm_1__COUNTER )
#define TimerHumidityTemp_COUNTER_PTR                    ( (reg32 *) TimerHumidityTemp_cy_m0s8_tcpwm_1__COUNTER )
#define TimerHumidityTemp_COMP_CAP_REG                   (*(reg32 *) TimerHumidityTemp_cy_m0s8_tcpwm_1__CC )
#define TimerHumidityTemp_COMP_CAP_PTR                   ( (reg32 *) TimerHumidityTemp_cy_m0s8_tcpwm_1__CC )
#define TimerHumidityTemp_COMP_CAP_BUF_REG               (*(reg32 *) TimerHumidityTemp_cy_m0s8_tcpwm_1__CC_BUFF )
#define TimerHumidityTemp_COMP_CAP_BUF_PTR               ( (reg32 *) TimerHumidityTemp_cy_m0s8_tcpwm_1__CC_BUFF )
#define TimerHumidityTemp_PERIOD_REG                     (*(reg32 *) TimerHumidityTemp_cy_m0s8_tcpwm_1__PERIOD )
#define TimerHumidityTemp_PERIOD_PTR                     ( (reg32 *) TimerHumidityTemp_cy_m0s8_tcpwm_1__PERIOD )
#define TimerHumidityTemp_PERIOD_BUF_REG                 (*(reg32 *) TimerHumidityTemp_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define TimerHumidityTemp_PERIOD_BUF_PTR                 ( (reg32 *) TimerHumidityTemp_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define TimerHumidityTemp_TRIG_CONTROL0_REG              (*(reg32 *) TimerHumidityTemp_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define TimerHumidityTemp_TRIG_CONTROL0_PTR              ( (reg32 *) TimerHumidityTemp_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define TimerHumidityTemp_TRIG_CONTROL1_REG              (*(reg32 *) TimerHumidityTemp_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define TimerHumidityTemp_TRIG_CONTROL1_PTR              ( (reg32 *) TimerHumidityTemp_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define TimerHumidityTemp_TRIG_CONTROL2_REG              (*(reg32 *) TimerHumidityTemp_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define TimerHumidityTemp_TRIG_CONTROL2_PTR              ( (reg32 *) TimerHumidityTemp_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define TimerHumidityTemp_INTERRUPT_REQ_REG              (*(reg32 *) TimerHumidityTemp_cy_m0s8_tcpwm_1__INTR )
#define TimerHumidityTemp_INTERRUPT_REQ_PTR              ( (reg32 *) TimerHumidityTemp_cy_m0s8_tcpwm_1__INTR )
#define TimerHumidityTemp_INTERRUPT_SET_REG              (*(reg32 *) TimerHumidityTemp_cy_m0s8_tcpwm_1__INTR_SET )
#define TimerHumidityTemp_INTERRUPT_SET_PTR              ( (reg32 *) TimerHumidityTemp_cy_m0s8_tcpwm_1__INTR_SET )
#define TimerHumidityTemp_INTERRUPT_MASK_REG             (*(reg32 *) TimerHumidityTemp_cy_m0s8_tcpwm_1__INTR_MASK )
#define TimerHumidityTemp_INTERRUPT_MASK_PTR             ( (reg32 *) TimerHumidityTemp_cy_m0s8_tcpwm_1__INTR_MASK )
#define TimerHumidityTemp_INTERRUPT_MASKED_REG           (*(reg32 *) TimerHumidityTemp_cy_m0s8_tcpwm_1__INTR_MASKED )
#define TimerHumidityTemp_INTERRUPT_MASKED_PTR           ( (reg32 *) TimerHumidityTemp_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define TimerHumidityTemp_MASK                           ((uint32)TimerHumidityTemp_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define TimerHumidityTemp_RELOAD_CC_SHIFT                (0u)
#define TimerHumidityTemp_RELOAD_PERIOD_SHIFT            (1u)
#define TimerHumidityTemp_PWM_SYNC_KILL_SHIFT            (2u)
#define TimerHumidityTemp_PWM_STOP_KILL_SHIFT            (3u)
#define TimerHumidityTemp_PRESCALER_SHIFT                (8u)
#define TimerHumidityTemp_UPDOWN_SHIFT                   (16u)
#define TimerHumidityTemp_ONESHOT_SHIFT                  (18u)
#define TimerHumidityTemp_QUAD_MODE_SHIFT                (20u)
#define TimerHumidityTemp_INV_OUT_SHIFT                  (20u)
#define TimerHumidityTemp_INV_COMPL_OUT_SHIFT            (21u)
#define TimerHumidityTemp_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define TimerHumidityTemp_RELOAD_CC_MASK                 ((uint32)(TimerHumidityTemp_1BIT_MASK        <<  \
                                                                            TimerHumidityTemp_RELOAD_CC_SHIFT))
#define TimerHumidityTemp_RELOAD_PERIOD_MASK             ((uint32)(TimerHumidityTemp_1BIT_MASK        <<  \
                                                                            TimerHumidityTemp_RELOAD_PERIOD_SHIFT))
#define TimerHumidityTemp_PWM_SYNC_KILL_MASK             ((uint32)(TimerHumidityTemp_1BIT_MASK        <<  \
                                                                            TimerHumidityTemp_PWM_SYNC_KILL_SHIFT))
#define TimerHumidityTemp_PWM_STOP_KILL_MASK             ((uint32)(TimerHumidityTemp_1BIT_MASK        <<  \
                                                                            TimerHumidityTemp_PWM_STOP_KILL_SHIFT))
#define TimerHumidityTemp_PRESCALER_MASK                 ((uint32)(TimerHumidityTemp_8BIT_MASK        <<  \
                                                                            TimerHumidityTemp_PRESCALER_SHIFT))
#define TimerHumidityTemp_UPDOWN_MASK                    ((uint32)(TimerHumidityTemp_2BIT_MASK        <<  \
                                                                            TimerHumidityTemp_UPDOWN_SHIFT))
#define TimerHumidityTemp_ONESHOT_MASK                   ((uint32)(TimerHumidityTemp_1BIT_MASK        <<  \
                                                                            TimerHumidityTemp_ONESHOT_SHIFT))
#define TimerHumidityTemp_QUAD_MODE_MASK                 ((uint32)(TimerHumidityTemp_3BIT_MASK        <<  \
                                                                            TimerHumidityTemp_QUAD_MODE_SHIFT))
#define TimerHumidityTemp_INV_OUT_MASK                   ((uint32)(TimerHumidityTemp_2BIT_MASK        <<  \
                                                                            TimerHumidityTemp_INV_OUT_SHIFT))
#define TimerHumidityTemp_MODE_MASK                      ((uint32)(TimerHumidityTemp_3BIT_MASK        <<  \
                                                                            TimerHumidityTemp_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define TimerHumidityTemp_CAPTURE_SHIFT                  (0u)
#define TimerHumidityTemp_COUNT_SHIFT                    (2u)
#define TimerHumidityTemp_RELOAD_SHIFT                   (4u)
#define TimerHumidityTemp_STOP_SHIFT                     (6u)
#define TimerHumidityTemp_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define TimerHumidityTemp_CAPTURE_MASK                   ((uint32)(TimerHumidityTemp_2BIT_MASK        <<  \
                                                                  TimerHumidityTemp_CAPTURE_SHIFT))
#define TimerHumidityTemp_COUNT_MASK                     ((uint32)(TimerHumidityTemp_2BIT_MASK        <<  \
                                                                  TimerHumidityTemp_COUNT_SHIFT))
#define TimerHumidityTemp_RELOAD_MASK                    ((uint32)(TimerHumidityTemp_2BIT_MASK        <<  \
                                                                  TimerHumidityTemp_RELOAD_SHIFT))
#define TimerHumidityTemp_STOP_MASK                      ((uint32)(TimerHumidityTemp_2BIT_MASK        <<  \
                                                                  TimerHumidityTemp_STOP_SHIFT))
#define TimerHumidityTemp_START_MASK                     ((uint32)(TimerHumidityTemp_2BIT_MASK        <<  \
                                                                  TimerHumidityTemp_START_SHIFT))

/* MASK */
#define TimerHumidityTemp_1BIT_MASK                      ((uint32)0x01u)
#define TimerHumidityTemp_2BIT_MASK                      ((uint32)0x03u)
#define TimerHumidityTemp_3BIT_MASK                      ((uint32)0x07u)
#define TimerHumidityTemp_6BIT_MASK                      ((uint32)0x3Fu)
#define TimerHumidityTemp_8BIT_MASK                      ((uint32)0xFFu)
#define TimerHumidityTemp_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define TimerHumidityTemp_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define TimerHumidityTemp_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(TimerHumidityTemp_QUAD_ENCODING_MODES     << TimerHumidityTemp_QUAD_MODE_SHIFT))       |\
         ((uint32)(TimerHumidityTemp_CONFIG                  << TimerHumidityTemp_MODE_SHIFT)))

#define TimerHumidityTemp_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(TimerHumidityTemp_PWM_STOP_EVENT          << TimerHumidityTemp_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(TimerHumidityTemp_PWM_OUT_INVERT          << TimerHumidityTemp_INV_OUT_SHIFT))         |\
         ((uint32)(TimerHumidityTemp_PWM_OUT_N_INVERT        << TimerHumidityTemp_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(TimerHumidityTemp_PWM_MODE                << TimerHumidityTemp_MODE_SHIFT)))

#define TimerHumidityTemp_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(TimerHumidityTemp_PWM_RUN_MODE         << TimerHumidityTemp_ONESHOT_SHIFT))
            
#define TimerHumidityTemp_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(TimerHumidityTemp_PWM_ALIGN            << TimerHumidityTemp_UPDOWN_SHIFT))

#define TimerHumidityTemp_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(TimerHumidityTemp_PWM_KILL_EVENT      << TimerHumidityTemp_PWM_SYNC_KILL_SHIFT))

#define TimerHumidityTemp_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(TimerHumidityTemp_PWM_DEAD_TIME_CYCLE  << TimerHumidityTemp_PRESCALER_SHIFT))

#define TimerHumidityTemp_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(TimerHumidityTemp_PWM_PRESCALER        << TimerHumidityTemp_PRESCALER_SHIFT))

#define TimerHumidityTemp_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(TimerHumidityTemp_TC_PRESCALER            << TimerHumidityTemp_PRESCALER_SHIFT))       |\
         ((uint32)(TimerHumidityTemp_TC_COUNTER_MODE         << TimerHumidityTemp_UPDOWN_SHIFT))          |\
         ((uint32)(TimerHumidityTemp_TC_RUN_MODE             << TimerHumidityTemp_ONESHOT_SHIFT))         |\
         ((uint32)(TimerHumidityTemp_TC_COMP_CAP_MODE        << TimerHumidityTemp_MODE_SHIFT)))
        
#define TimerHumidityTemp_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(TimerHumidityTemp_QUAD_PHIA_SIGNAL_MODE   << TimerHumidityTemp_COUNT_SHIFT))           |\
         ((uint32)(TimerHumidityTemp_QUAD_INDEX_SIGNAL_MODE  << TimerHumidityTemp_RELOAD_SHIFT))          |\
         ((uint32)(TimerHumidityTemp_QUAD_STOP_SIGNAL_MODE   << TimerHumidityTemp_STOP_SHIFT))            |\
         ((uint32)(TimerHumidityTemp_QUAD_PHIB_SIGNAL_MODE   << TimerHumidityTemp_START_SHIFT)))

#define TimerHumidityTemp_PWM_SIGNALS_MODES                                                              \
        (((uint32)(TimerHumidityTemp_PWM_SWITCH_SIGNAL_MODE  << TimerHumidityTemp_CAPTURE_SHIFT))         |\
         ((uint32)(TimerHumidityTemp_PWM_COUNT_SIGNAL_MODE   << TimerHumidityTemp_COUNT_SHIFT))           |\
         ((uint32)(TimerHumidityTemp_PWM_RELOAD_SIGNAL_MODE  << TimerHumidityTemp_RELOAD_SHIFT))          |\
         ((uint32)(TimerHumidityTemp_PWM_STOP_SIGNAL_MODE    << TimerHumidityTemp_STOP_SHIFT))            |\
         ((uint32)(TimerHumidityTemp_PWM_START_SIGNAL_MODE   << TimerHumidityTemp_START_SHIFT)))

#define TimerHumidityTemp_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(TimerHumidityTemp_TC_CAPTURE_SIGNAL_MODE  << TimerHumidityTemp_CAPTURE_SHIFT))         |\
         ((uint32)(TimerHumidityTemp_TC_COUNT_SIGNAL_MODE    << TimerHumidityTemp_COUNT_SHIFT))           |\
         ((uint32)(TimerHumidityTemp_TC_RELOAD_SIGNAL_MODE   << TimerHumidityTemp_RELOAD_SHIFT))          |\
         ((uint32)(TimerHumidityTemp_TC_STOP_SIGNAL_MODE     << TimerHumidityTemp_STOP_SHIFT))            |\
         ((uint32)(TimerHumidityTemp_TC_START_SIGNAL_MODE    << TimerHumidityTemp_START_SHIFT)))
        
#define TimerHumidityTemp_TIMER_UPDOWN_CNT_USED                                                          \
                ((TimerHumidityTemp__COUNT_UPDOWN0 == TimerHumidityTemp_TC_COUNTER_MODE)                  ||\
                 (TimerHumidityTemp__COUNT_UPDOWN1 == TimerHumidityTemp_TC_COUNTER_MODE))

#define TimerHumidityTemp_PWM_UPDOWN_CNT_USED                                                            \
                ((TimerHumidityTemp__CENTER == TimerHumidityTemp_PWM_ALIGN)                               ||\
                 (TimerHumidityTemp__ASYMMETRIC == TimerHumidityTemp_PWM_ALIGN))               
        
#define TimerHumidityTemp_PWM_PR_INIT_VALUE              (1u)
#define TimerHumidityTemp_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_TimerHumidityTemp_H */

/* [] END OF FILE */
