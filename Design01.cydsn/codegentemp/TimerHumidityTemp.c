/*******************************************************************************
* File Name: TimerHumidityTemp.c
* Version 2.10
*
* Description:
*  This file provides the source code to the API for the TimerHumidityTemp
*  component
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

#include "TimerHumidityTemp.h"

uint8 TimerHumidityTemp_initVar = 0u;


/*******************************************************************************
* Function Name: TimerHumidityTemp_Init
********************************************************************************
*
* Summary:
*  Initialize/Restore default TimerHumidityTemp configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void TimerHumidityTemp_Init(void)
{

    /* Set values from customizer to CTRL */
    #if (TimerHumidityTemp__QUAD == TimerHumidityTemp_CONFIG)
        TimerHumidityTemp_CONTROL_REG = TimerHumidityTemp_CTRL_QUAD_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        TimerHumidityTemp_TRIG_CONTROL1_REG  = TimerHumidityTemp_QUAD_SIGNALS_MODES;

        /* Set values from customizer to INTR */
        TimerHumidityTemp_SetInterruptMode(TimerHumidityTemp_QUAD_INTERRUPT_MASK);
        
         /* Set other values */
        TimerHumidityTemp_SetCounterMode(TimerHumidityTemp_COUNT_DOWN);
        TimerHumidityTemp_WritePeriod(TimerHumidityTemp_QUAD_PERIOD_INIT_VALUE);
        TimerHumidityTemp_WriteCounter(TimerHumidityTemp_QUAD_PERIOD_INIT_VALUE);
    #endif  /* (TimerHumidityTemp__QUAD == TimerHumidityTemp_CONFIG) */

    #if (TimerHumidityTemp__TIMER == TimerHumidityTemp_CONFIG)
        TimerHumidityTemp_CONTROL_REG = TimerHumidityTemp_CTRL_TIMER_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        TimerHumidityTemp_TRIG_CONTROL1_REG  = TimerHumidityTemp_TIMER_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        TimerHumidityTemp_SetInterruptMode(TimerHumidityTemp_TC_INTERRUPT_MASK);
        
        /* Set other values from customizer */
        TimerHumidityTemp_WritePeriod(TimerHumidityTemp_TC_PERIOD_VALUE );

        #if (TimerHumidityTemp__COMPARE == TimerHumidityTemp_TC_COMP_CAP_MODE)
            TimerHumidityTemp_WriteCompare(TimerHumidityTemp_TC_COMPARE_VALUE);

            #if (1u == TimerHumidityTemp_TC_COMPARE_SWAP)
                TimerHumidityTemp_SetCompareSwap(1u);
                TimerHumidityTemp_WriteCompareBuf(TimerHumidityTemp_TC_COMPARE_BUF_VALUE);
            #endif  /* (1u == TimerHumidityTemp_TC_COMPARE_SWAP) */
        #endif  /* (TimerHumidityTemp__COMPARE == TimerHumidityTemp_TC_COMP_CAP_MODE) */

        /* Initialize counter value */
        #if (TimerHumidityTemp_CY_TCPWM_V2 && TimerHumidityTemp_TIMER_UPDOWN_CNT_USED && !TimerHumidityTemp_CY_TCPWM_4000)
            TimerHumidityTemp_WriteCounter(1u);
        #elif(TimerHumidityTemp__COUNT_DOWN == TimerHumidityTemp_TC_COUNTER_MODE)
            TimerHumidityTemp_WriteCounter(TimerHumidityTemp_TC_PERIOD_VALUE);
        #else
            TimerHumidityTemp_WriteCounter(0u);
        #endif /* (TimerHumidityTemp_CY_TCPWM_V2 && TimerHumidityTemp_TIMER_UPDOWN_CNT_USED && !TimerHumidityTemp_CY_TCPWM_4000) */
    #endif  /* (TimerHumidityTemp__TIMER == TimerHumidityTemp_CONFIG) */

    #if (TimerHumidityTemp__PWM_SEL == TimerHumidityTemp_CONFIG)
        TimerHumidityTemp_CONTROL_REG = TimerHumidityTemp_CTRL_PWM_BASE_CONFIG;

        #if (TimerHumidityTemp__PWM_PR == TimerHumidityTemp_PWM_MODE)
            TimerHumidityTemp_CONTROL_REG |= TimerHumidityTemp_CTRL_PWM_RUN_MODE;
            TimerHumidityTemp_WriteCounter(TimerHumidityTemp_PWM_PR_INIT_VALUE);
        #else
            TimerHumidityTemp_CONTROL_REG |= TimerHumidityTemp_CTRL_PWM_ALIGN | TimerHumidityTemp_CTRL_PWM_KILL_EVENT;
            
            /* Initialize counter value */
            #if (TimerHumidityTemp_CY_TCPWM_V2 && TimerHumidityTemp_PWM_UPDOWN_CNT_USED && !TimerHumidityTemp_CY_TCPWM_4000)
                TimerHumidityTemp_WriteCounter(1u);
            #elif (TimerHumidityTemp__RIGHT == TimerHumidityTemp_PWM_ALIGN)
                TimerHumidityTemp_WriteCounter(TimerHumidityTemp_PWM_PERIOD_VALUE);
            #else 
                TimerHumidityTemp_WriteCounter(0u);
            #endif  /* (TimerHumidityTemp_CY_TCPWM_V2 && TimerHumidityTemp_PWM_UPDOWN_CNT_USED && !TimerHumidityTemp_CY_TCPWM_4000) */
        #endif  /* (TimerHumidityTemp__PWM_PR == TimerHumidityTemp_PWM_MODE) */

        #if (TimerHumidityTemp__PWM_DT == TimerHumidityTemp_PWM_MODE)
            TimerHumidityTemp_CONTROL_REG |= TimerHumidityTemp_CTRL_PWM_DEAD_TIME_CYCLE;
        #endif  /* (TimerHumidityTemp__PWM_DT == TimerHumidityTemp_PWM_MODE) */

        #if (TimerHumidityTemp__PWM == TimerHumidityTemp_PWM_MODE)
            TimerHumidityTemp_CONTROL_REG |= TimerHumidityTemp_CTRL_PWM_PRESCALER;
        #endif  /* (TimerHumidityTemp__PWM == TimerHumidityTemp_PWM_MODE) */

        /* Set values from customizer to CTRL1 */
        TimerHumidityTemp_TRIG_CONTROL1_REG  = TimerHumidityTemp_PWM_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        TimerHumidityTemp_SetInterruptMode(TimerHumidityTemp_PWM_INTERRUPT_MASK);

        /* Set values from customizer to CTRL2 */
        #if (TimerHumidityTemp__PWM_PR == TimerHumidityTemp_PWM_MODE)
            TimerHumidityTemp_TRIG_CONTROL2_REG =
                    (TimerHumidityTemp_CC_MATCH_NO_CHANGE    |
                    TimerHumidityTemp_OVERLOW_NO_CHANGE      |
                    TimerHumidityTemp_UNDERFLOW_NO_CHANGE);
        #else
            #if (TimerHumidityTemp__LEFT == TimerHumidityTemp_PWM_ALIGN)
                TimerHumidityTemp_TRIG_CONTROL2_REG = TimerHumidityTemp_PWM_MODE_LEFT;
            #endif  /* ( TimerHumidityTemp_PWM_LEFT == TimerHumidityTemp_PWM_ALIGN) */

            #if (TimerHumidityTemp__RIGHT == TimerHumidityTemp_PWM_ALIGN)
                TimerHumidityTemp_TRIG_CONTROL2_REG = TimerHumidityTemp_PWM_MODE_RIGHT;
            #endif  /* ( TimerHumidityTemp_PWM_RIGHT == TimerHumidityTemp_PWM_ALIGN) */

            #if (TimerHumidityTemp__CENTER == TimerHumidityTemp_PWM_ALIGN)
                TimerHumidityTemp_TRIG_CONTROL2_REG = TimerHumidityTemp_PWM_MODE_CENTER;
            #endif  /* ( TimerHumidityTemp_PWM_CENTER == TimerHumidityTemp_PWM_ALIGN) */

            #if (TimerHumidityTemp__ASYMMETRIC == TimerHumidityTemp_PWM_ALIGN)
                TimerHumidityTemp_TRIG_CONTROL2_REG = TimerHumidityTemp_PWM_MODE_ASYM;
            #endif  /* (TimerHumidityTemp__ASYMMETRIC == TimerHumidityTemp_PWM_ALIGN) */
        #endif  /* (TimerHumidityTemp__PWM_PR == TimerHumidityTemp_PWM_MODE) */

        /* Set other values from customizer */
        TimerHumidityTemp_WritePeriod(TimerHumidityTemp_PWM_PERIOD_VALUE );
        TimerHumidityTemp_WriteCompare(TimerHumidityTemp_PWM_COMPARE_VALUE);

        #if (1u == TimerHumidityTemp_PWM_COMPARE_SWAP)
            TimerHumidityTemp_SetCompareSwap(1u);
            TimerHumidityTemp_WriteCompareBuf(TimerHumidityTemp_PWM_COMPARE_BUF_VALUE);
        #endif  /* (1u == TimerHumidityTemp_PWM_COMPARE_SWAP) */

        #if (1u == TimerHumidityTemp_PWM_PERIOD_SWAP)
            TimerHumidityTemp_SetPeriodSwap(1u);
            TimerHumidityTemp_WritePeriodBuf(TimerHumidityTemp_PWM_PERIOD_BUF_VALUE);
        #endif  /* (1u == TimerHumidityTemp_PWM_PERIOD_SWAP) */
    #endif  /* (TimerHumidityTemp__PWM_SEL == TimerHumidityTemp_CONFIG) */
    
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_Enable
********************************************************************************
*
* Summary:
*  Enables the TimerHumidityTemp.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void TimerHumidityTemp_Enable(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    TimerHumidityTemp_BLOCK_CONTROL_REG |= TimerHumidityTemp_MASK;
    CyExitCriticalSection(enableInterrupts);

    /* Start Timer or PWM if start input is absent */
    #if (TimerHumidityTemp__PWM_SEL == TimerHumidityTemp_CONFIG)
        #if (0u == TimerHumidityTemp_PWM_START_SIGNAL_PRESENT)
            TimerHumidityTemp_TriggerCommand(TimerHumidityTemp_MASK, TimerHumidityTemp_CMD_START);
        #endif /* (0u == TimerHumidityTemp_PWM_START_SIGNAL_PRESENT) */
    #endif /* (TimerHumidityTemp__PWM_SEL == TimerHumidityTemp_CONFIG) */

    #if (TimerHumidityTemp__TIMER == TimerHumidityTemp_CONFIG)
        #if (0u == TimerHumidityTemp_TC_START_SIGNAL_PRESENT)
            TimerHumidityTemp_TriggerCommand(TimerHumidityTemp_MASK, TimerHumidityTemp_CMD_START);
        #endif /* (0u == TimerHumidityTemp_TC_START_SIGNAL_PRESENT) */
    #endif /* (TimerHumidityTemp__TIMER == TimerHumidityTemp_CONFIG) */
    
    #if (TimerHumidityTemp__QUAD == TimerHumidityTemp_CONFIG)
        #if (0u != TimerHumidityTemp_QUAD_AUTO_START)
            TimerHumidityTemp_TriggerCommand(TimerHumidityTemp_MASK, TimerHumidityTemp_CMD_RELOAD);
        #endif /* (0u != TimerHumidityTemp_QUAD_AUTO_START) */
    #endif  /* (TimerHumidityTemp__QUAD == TimerHumidityTemp_CONFIG) */
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_Start
********************************************************************************
*
* Summary:
*  Initializes the TimerHumidityTemp with default customizer
*  values when called the first time and enables the TimerHumidityTemp.
*  For subsequent calls the configuration is left unchanged and the component is
*  just enabled.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  TimerHumidityTemp_initVar: global variable is used to indicate initial
*  configuration of this component.  The variable is initialized to zero and set
*  to 1 the first time TimerHumidityTemp_Start() is called. This allows
*  enabling/disabling a component without re-initialization in all subsequent
*  calls to the TimerHumidityTemp_Start() routine.
*
*******************************************************************************/
void TimerHumidityTemp_Start(void)
{
    if (0u == TimerHumidityTemp_initVar)
    {
        TimerHumidityTemp_Init();
        TimerHumidityTemp_initVar = 1u;
    }

    TimerHumidityTemp_Enable();
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_Stop
********************************************************************************
*
* Summary:
*  Disables the TimerHumidityTemp.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void TimerHumidityTemp_Stop(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TimerHumidityTemp_BLOCK_CONTROL_REG &= (uint32)~TimerHumidityTemp_MASK;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_SetMode
********************************************************************************
*
* Summary:
*  Sets the operation mode of the TimerHumidityTemp. This function is used when
*  configured as a generic TimerHumidityTemp and the actual mode of operation is
*  set at runtime. The mode must be set while the component is disabled.
*
* Parameters:
*  mode: Mode for the TimerHumidityTemp to operate in
*   Values:
*   - TimerHumidityTemp_MODE_TIMER_COMPARE - Timer / Counter with
*                                                 compare capability
*         - TimerHumidityTemp_MODE_TIMER_CAPTURE - Timer / Counter with
*                                                 capture capability
*         - TimerHumidityTemp_MODE_QUAD - Quadrature decoder
*         - TimerHumidityTemp_MODE_PWM - PWM
*         - TimerHumidityTemp_MODE_PWM_DT - PWM with dead time
*         - TimerHumidityTemp_MODE_PWM_PR - PWM with pseudo random capability
*
* Return:
*  None
*
*******************************************************************************/
void TimerHumidityTemp_SetMode(uint32 mode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TimerHumidityTemp_CONTROL_REG &= (uint32)~TimerHumidityTemp_MODE_MASK;
    TimerHumidityTemp_CONTROL_REG |= mode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_SetQDMode
********************************************************************************
*
* Summary:
*  Sets the the Quadrature Decoder to one of the 3 supported modes.
*  Its functionality is only applicable to Quadrature Decoder operation.
*
* Parameters:
*  qdMode: Quadrature Decoder mode
*   Values:
*         - TimerHumidityTemp_MODE_X1 - Counts on phi 1 rising
*         - TimerHumidityTemp_MODE_X2 - Counts on both edges of phi1 (2x faster)
*         - TimerHumidityTemp_MODE_X4 - Counts on both edges of phi1 and phi2
*                                        (4x faster)
*
* Return:
*  None
*
*******************************************************************************/
void TimerHumidityTemp_SetQDMode(uint32 qdMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TimerHumidityTemp_CONTROL_REG &= (uint32)~TimerHumidityTemp_QUAD_MODE_MASK;
    TimerHumidityTemp_CONTROL_REG |= qdMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_SetPrescaler
********************************************************************************
*
* Summary:
*  Sets the prescaler value that is applied to the clock input.  Not applicable
*  to a PWM with the dead time mode or Quadrature Decoder mode.
*
* Parameters:
*  prescaler: Prescaler divider value
*   Values:
*         - TimerHumidityTemp_PRESCALE_DIVBY1    - Divide by 1 (no prescaling)
*         - TimerHumidityTemp_PRESCALE_DIVBY2    - Divide by 2
*         - TimerHumidityTemp_PRESCALE_DIVBY4    - Divide by 4
*         - TimerHumidityTemp_PRESCALE_DIVBY8    - Divide by 8
*         - TimerHumidityTemp_PRESCALE_DIVBY16   - Divide by 16
*         - TimerHumidityTemp_PRESCALE_DIVBY32   - Divide by 32
*         - TimerHumidityTemp_PRESCALE_DIVBY64   - Divide by 64
*         - TimerHumidityTemp_PRESCALE_DIVBY128  - Divide by 128
*
* Return:
*  None
*
*******************************************************************************/
void TimerHumidityTemp_SetPrescaler(uint32 prescaler)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TimerHumidityTemp_CONTROL_REG &= (uint32)~TimerHumidityTemp_PRESCALER_MASK;
    TimerHumidityTemp_CONTROL_REG |= prescaler;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_SetOneShot
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the TimerHumidityTemp runs
*  continuously or stops when terminal count is reached.  By default the
*  TimerHumidityTemp operates in the continuous mode.
*
* Parameters:
*  oneShotEnable
*   Values:
*     - 0 - Continuous
*     - 1 - Enable One Shot
*
* Return:
*  None
*
*******************************************************************************/
void TimerHumidityTemp_SetOneShot(uint32 oneShotEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TimerHumidityTemp_CONTROL_REG &= (uint32)~TimerHumidityTemp_ONESHOT_MASK;
    TimerHumidityTemp_CONTROL_REG |= ((uint32)((oneShotEnable & TimerHumidityTemp_1BIT_MASK) <<
                                                               TimerHumidityTemp_ONESHOT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_SetPWMMode
********************************************************************************
*
* Summary:
*  Writes the control register that determines what mode of operation the PWM
*  output lines are driven in.  There is a setting for what to do on a
*  comparison match (CC_MATCH), on an overflow (OVERFLOW) and on an underflow
*  (UNDERFLOW).  The value for each of the three must be ORed together to form
*  the mode.
*
* Parameters:
*  modeMask: A combination of three mode settings.  Mask must include a value
*  for each of the three or use one of the preconfigured PWM settings.
*   Values:
*     - CC_MATCH_SET        - Set on comparison match
*     - CC_MATCH_CLEAR      - Clear on comparison match
*     - CC_MATCH_INVERT     - Invert on comparison match
*     - CC_MATCH_NO_CHANGE  - No change on comparison match
*     - OVERLOW_SET         - Set on overflow
*     - OVERLOW_CLEAR       - Clear on  overflow
*     - OVERLOW_INVERT      - Invert on overflow
*     - OVERLOW_NO_CHANGE   - No change on overflow
*     - UNDERFLOW_SET       - Set on underflow
*     - UNDERFLOW_CLEAR     - Clear on underflow
*     - UNDERFLOW_INVERT    - Invert on underflow
*     - UNDERFLOW_NO_CHANGE - No change on underflow
*     - PWM_MODE_LEFT       - Setting for left aligned PWM.  Should be combined
*                             with up counting mode
*     - PWM_MODE_RIGHT      - Setting for right aligned PWM.  Should be combined
*                             with down counting mode
*     - PWM_MODE_CENTER     - Setting for center aligned PWM.  Should be
*                             combined with up/down 0 mode
*     - PWM_MODE_ASYM       - Setting for asymmetric PWM.  Should be combined
*                             with up/down 1 mode
*
* Return:
*  None
*
*******************************************************************************/
void TimerHumidityTemp_SetPWMMode(uint32 modeMask)
{
    TimerHumidityTemp_TRIG_CONTROL2_REG = (modeMask & TimerHumidityTemp_6BIT_MASK);
}



/*******************************************************************************
* Function Name: TimerHumidityTemp_SetPWMSyncKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes asynchronous or synchronous kill operation.  By default the kill
*  operation is asynchronous.  This functionality is only applicable to the PWM
*  and PWM with dead time modes.
*
*  For Synchronous mode the kill signal disables both the line and line_n
*  signals until the next terminal count.
*
*  For Asynchronous mode the kill signal disables both the line and line_n
*  signals when the kill signal is present.  This mode should only be used
*  when the kill signal (stop input) is configured in the pass through mode
*  (Level sensitive signal).

*
* Parameters:
*  syncKillEnable
*   Values:
*     - 0 - Asynchronous
*     - 1 - Synchronous
*
* Return:
*  None
*
*******************************************************************************/
void TimerHumidityTemp_SetPWMSyncKill(uint32 syncKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TimerHumidityTemp_CONTROL_REG &= (uint32)~TimerHumidityTemp_PWM_SYNC_KILL_MASK;
    TimerHumidityTemp_CONTROL_REG |= ((uint32)((syncKillEnable & TimerHumidityTemp_1BIT_MASK)  <<
                                               TimerHumidityTemp_PWM_SYNC_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_SetPWMStopOnKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes the PWM counter to stop.  By default the kill operation does not stop
*  the counter.  This functionality is only applicable to the three PWM modes.
*
*
* Parameters:
*  stopOnKillEnable
*   Values:
*     - 0 - Don't stop
*     - 1 - Stop
*
* Return:
*  None
*
*******************************************************************************/
void TimerHumidityTemp_SetPWMStopOnKill(uint32 stopOnKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TimerHumidityTemp_CONTROL_REG &= (uint32)~TimerHumidityTemp_PWM_STOP_KILL_MASK;
    TimerHumidityTemp_CONTROL_REG |= ((uint32)((stopOnKillEnable & TimerHumidityTemp_1BIT_MASK)  <<
                                                         TimerHumidityTemp_PWM_STOP_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_SetPWMDeadTime
********************************************************************************
*
* Summary:
*  Writes the dead time control value.  This value delays the rising edge of
*  both the line and line_n signals the designated number of cycles resulting
*  in both signals being inactive for that many cycles.  This functionality is
*  only applicable to the PWM in the dead time mode.

*
* Parameters:
*  Dead time to insert
*   Values: 0 to 255
*
* Return:
*  None
*
*******************************************************************************/
void TimerHumidityTemp_SetPWMDeadTime(uint32 deadTime)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TimerHumidityTemp_CONTROL_REG &= (uint32)~TimerHumidityTemp_PRESCALER_MASK;
    TimerHumidityTemp_CONTROL_REG |= ((uint32)((deadTime & TimerHumidityTemp_8BIT_MASK) <<
                                                          TimerHumidityTemp_PRESCALER_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_SetPWMInvert
********************************************************************************
*
* Summary:
*  Writes the bits that control whether the line and line_n outputs are
*  inverted from their normal output values.  This functionality is only
*  applicable to the three PWM modes.
*
* Parameters:
*  mask: Mask of outputs to invert.
*   Values:
*         - TimerHumidityTemp_INVERT_LINE   - Inverts the line output
*         - TimerHumidityTemp_INVERT_LINE_N - Inverts the line_n output
*
* Return:
*  None
*
*******************************************************************************/
void TimerHumidityTemp_SetPWMInvert(uint32 mask)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TimerHumidityTemp_CONTROL_REG &= (uint32)~TimerHumidityTemp_INV_OUT_MASK;
    TimerHumidityTemp_CONTROL_REG |= mask;

    CyExitCriticalSection(enableInterrupts);
}



/*******************************************************************************
* Function Name: TimerHumidityTemp_WriteCounter
********************************************************************************
*
* Summary:
*  Writes a new 16bit counter value directly into the counter register, thus
*  setting the counter (not the period) to the value written. It is not
*  advised to write to this field when the counter is running.
*
* Parameters:
*  count: value to write
*
* Return:
*  None
*
*******************************************************************************/
void TimerHumidityTemp_WriteCounter(uint32 count)
{
    TimerHumidityTemp_COUNTER_REG = (count & TimerHumidityTemp_16BIT_MASK);
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_ReadCounter
********************************************************************************
*
* Summary:
*  Reads the current counter value.
*
* Parameters:
*  None
*
* Return:
*  Current counter value
*
*******************************************************************************/
uint32 TimerHumidityTemp_ReadCounter(void)
{
    return (TimerHumidityTemp_COUNTER_REG & TimerHumidityTemp_16BIT_MASK);
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_SetCounterMode
********************************************************************************
*
* Summary:
*  Sets the counter mode.  Applicable to all modes except Quadrature Decoder
*  and the PWM with a pseudo random output.
*
* Parameters:
*  counterMode: Enumerated counter type values
*   Values:
*     - TimerHumidityTemp_COUNT_UP       - Counts up
*     - TimerHumidityTemp_COUNT_DOWN     - Counts down
*     - TimerHumidityTemp_COUNT_UPDOWN0  - Counts up and down. Terminal count
*                                         generated when counter reaches 0
*     - TimerHumidityTemp_COUNT_UPDOWN1  - Counts up and down. Terminal count
*                                         generated both when counter reaches 0
*                                         and period
*
* Return:
*  None
*
*******************************************************************************/
void TimerHumidityTemp_SetCounterMode(uint32 counterMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TimerHumidityTemp_CONTROL_REG &= (uint32)~TimerHumidityTemp_UPDOWN_MASK;
    TimerHumidityTemp_CONTROL_REG |= counterMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_WritePeriod
********************************************************************************
*
* Summary:
*  Writes the 16 bit period register with the new period value.
*  To cause the counter to count for N cycles this register should be written
*  with N-1 (counts from 0 to period inclusive).
*
* Parameters:
*  period: Period value
*
* Return:
*  None
*
*******************************************************************************/
void TimerHumidityTemp_WritePeriod(uint32 period)
{
    TimerHumidityTemp_PERIOD_REG = (period & TimerHumidityTemp_16BIT_MASK);
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_ReadPeriod
********************************************************************************
*
* Summary:
*  Reads the 16 bit period register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 TimerHumidityTemp_ReadPeriod(void)
{
    return (TimerHumidityTemp_PERIOD_REG & TimerHumidityTemp_16BIT_MASK);
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_SetCompareSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the compare registers are
*  swapped. When enabled in the Timer/Counter mode(without capture) the swap
*  occurs at a TC event. In the PWM mode the swap occurs at the next TC event
*  following a hardware switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void TimerHumidityTemp_SetCompareSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TimerHumidityTemp_CONTROL_REG &= (uint32)~TimerHumidityTemp_RELOAD_CC_MASK;
    TimerHumidityTemp_CONTROL_REG |= (swapEnable & TimerHumidityTemp_1BIT_MASK);

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_WritePeriodBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit period buf register with the new period value.
*
* Parameters:
*  periodBuf: Period value
*
* Return:
*  None
*
*******************************************************************************/
void TimerHumidityTemp_WritePeriodBuf(uint32 periodBuf)
{
    TimerHumidityTemp_PERIOD_BUF_REG = (periodBuf & TimerHumidityTemp_16BIT_MASK);
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_ReadPeriodBuf
********************************************************************************
*
* Summary:
*  Reads the 16 bit period buf register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 TimerHumidityTemp_ReadPeriodBuf(void)
{
    return (TimerHumidityTemp_PERIOD_BUF_REG & TimerHumidityTemp_16BIT_MASK);
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_SetPeriodSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the period registers are
*  swapped. When enabled in Timer/Counter mode the swap occurs at a TC event.
*  In the PWM mode the swap occurs at the next TC event following a hardware
*  switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void TimerHumidityTemp_SetPeriodSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TimerHumidityTemp_CONTROL_REG &= (uint32)~TimerHumidityTemp_RELOAD_PERIOD_MASK;
    TimerHumidityTemp_CONTROL_REG |= ((uint32)((swapEnable & TimerHumidityTemp_1BIT_MASK) <<
                                                            TimerHumidityTemp_RELOAD_PERIOD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_WriteCompare
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compare: Compare value
*
* Return:
*  None
*
* Note:
*  It is not recommended to use the value equal to "0" or equal to 
*  "period value" in Center or Asymmetric align PWM modes on the 
*  PSoC 4100/PSoC 4200 devices.
*  PSoC 4000 devices write the 16 bit compare register with the decremented 
*  compare value in the Up counting mode (except 0x0u), and the incremented 
*  compare value in the Down counting mode (except 0xFFFFu).
*
*******************************************************************************/
void TimerHumidityTemp_WriteCompare(uint32 compare)
{
    #if (TimerHumidityTemp_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (TimerHumidityTemp_CY_TCPWM_4000) */

    #if (TimerHumidityTemp_CY_TCPWM_4000)
        currentMode = ((TimerHumidityTemp_CONTROL_REG & TimerHumidityTemp_UPDOWN_MASK) >> TimerHumidityTemp_UPDOWN_SHIFT);

        if (((uint32)TimerHumidityTemp__COUNT_DOWN == currentMode) && (0xFFFFu != compare))
        {
            compare++;
        }
        else if (((uint32)TimerHumidityTemp__COUNT_UP == currentMode) && (0u != compare))
        {
            compare--;
        }
        else
        {
        }
        
    
    #endif /* (TimerHumidityTemp_CY_TCPWM_4000) */
    
    TimerHumidityTemp_COMP_CAP_REG = (compare & TimerHumidityTemp_16BIT_MASK);
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_ReadCompare
********************************************************************************
*
* Summary:
*  Reads the compare register. Not applicable for Timer/Counter with Capture
*  or in Quadrature Decoder modes.
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
* Parameters:
*  None
*
* Return:
*  Compare value
*
* Note:
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
*******************************************************************************/
uint32 TimerHumidityTemp_ReadCompare(void)
{
    #if (TimerHumidityTemp_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (TimerHumidityTemp_CY_TCPWM_4000) */

    #if (TimerHumidityTemp_CY_TCPWM_4000)
        currentMode = ((TimerHumidityTemp_CONTROL_REG & TimerHumidityTemp_UPDOWN_MASK) >> TimerHumidityTemp_UPDOWN_SHIFT);
        
        regVal = TimerHumidityTemp_COMP_CAP_REG;
        
        if (((uint32)TimerHumidityTemp__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)TimerHumidityTemp__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & TimerHumidityTemp_16BIT_MASK);
    #else
        return (TimerHumidityTemp_COMP_CAP_REG & TimerHumidityTemp_16BIT_MASK);
    #endif /* (TimerHumidityTemp_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_WriteCompareBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare buffer register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compareBuf: Compare value
*
* Return:
*  None
*
* Note:
*  It is not recommended to use the value equal to "0" or equal to 
*  "period value" in Center or Asymmetric align PWM modes on the 
*  PSoC 4100/PSoC 4200 devices.
*  PSoC 4000 devices write the 16 bit compare register with the decremented 
*  compare value in the Up counting mode (except 0x0u), and the incremented 
*  compare value in the Down counting mode (except 0xFFFFu).
*
*******************************************************************************/
void TimerHumidityTemp_WriteCompareBuf(uint32 compareBuf)
{
    #if (TimerHumidityTemp_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (TimerHumidityTemp_CY_TCPWM_4000) */

    #if (TimerHumidityTemp_CY_TCPWM_4000)
        currentMode = ((TimerHumidityTemp_CONTROL_REG & TimerHumidityTemp_UPDOWN_MASK) >> TimerHumidityTemp_UPDOWN_SHIFT);

        if (((uint32)TimerHumidityTemp__COUNT_DOWN == currentMode) && (0xFFFFu != compareBuf))
        {
            compareBuf++;
        }
        else if (((uint32)TimerHumidityTemp__COUNT_UP == currentMode) && (0u != compareBuf))
        {
            compareBuf --;
        }
        else
        {
        }
    #endif /* (TimerHumidityTemp_CY_TCPWM_4000) */
    
    TimerHumidityTemp_COMP_CAP_BUF_REG = (compareBuf & TimerHumidityTemp_16BIT_MASK);
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_ReadCompareBuf
********************************************************************************
*
* Summary:
*  Reads the compare buffer register. Not applicable for Timer/Counter with
*  Capture or in Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Compare buffer value
*
* Note:
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
*******************************************************************************/
uint32 TimerHumidityTemp_ReadCompareBuf(void)
{
    #if (TimerHumidityTemp_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (TimerHumidityTemp_CY_TCPWM_4000) */

    #if (TimerHumidityTemp_CY_TCPWM_4000)
        currentMode = ((TimerHumidityTemp_CONTROL_REG & TimerHumidityTemp_UPDOWN_MASK) >> TimerHumidityTemp_UPDOWN_SHIFT);

        regVal = TimerHumidityTemp_COMP_CAP_BUF_REG;
        
        if (((uint32)TimerHumidityTemp__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)TimerHumidityTemp__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & TimerHumidityTemp_16BIT_MASK);
    #else
        return (TimerHumidityTemp_COMP_CAP_BUF_REG & TimerHumidityTemp_16BIT_MASK);
    #endif /* (TimerHumidityTemp_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_ReadCapture
********************************************************************************
*
* Summary:
*  Reads the captured counter value. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture value
*
*******************************************************************************/
uint32 TimerHumidityTemp_ReadCapture(void)
{
    return (TimerHumidityTemp_COMP_CAP_REG & TimerHumidityTemp_16BIT_MASK);
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_ReadCaptureBuf
********************************************************************************
*
* Summary:
*  Reads the capture buffer register. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture buffer value
*
*******************************************************************************/
uint32 TimerHumidityTemp_ReadCaptureBuf(void)
{
    return (TimerHumidityTemp_COMP_CAP_BUF_REG & TimerHumidityTemp_16BIT_MASK);
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_SetCaptureMode
********************************************************************************
*
* Summary:
*  Sets the capture trigger mode. For PWM mode this is the switch input.
*  This input is not applicable to the Timer/Counter without Capture and
*  Quadrature Decoder modes.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - TimerHumidityTemp_TRIG_LEVEL     - Level
*     - TimerHumidityTemp_TRIG_RISING    - Rising edge
*     - TimerHumidityTemp_TRIG_FALLING   - Falling edge
*     - TimerHumidityTemp_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void TimerHumidityTemp_SetCaptureMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TimerHumidityTemp_TRIG_CONTROL1_REG &= (uint32)~TimerHumidityTemp_CAPTURE_MASK;
    TimerHumidityTemp_TRIG_CONTROL1_REG |= triggerMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_SetReloadMode
********************************************************************************
*
* Summary:
*  Sets the reload trigger mode. For Quadrature Decoder mode this is the index
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - TimerHumidityTemp_TRIG_LEVEL     - Level
*     - TimerHumidityTemp_TRIG_RISING    - Rising edge
*     - TimerHumidityTemp_TRIG_FALLING   - Falling edge
*     - TimerHumidityTemp_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void TimerHumidityTemp_SetReloadMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TimerHumidityTemp_TRIG_CONTROL1_REG &= (uint32)~TimerHumidityTemp_RELOAD_MASK;
    TimerHumidityTemp_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << TimerHumidityTemp_RELOAD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_SetStartMode
********************************************************************************
*
* Summary:
*  Sets the start trigger mode. For Quadrature Decoder mode this is the
*  phiB input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - TimerHumidityTemp_TRIG_LEVEL     - Level
*     - TimerHumidityTemp_TRIG_RISING    - Rising edge
*     - TimerHumidityTemp_TRIG_FALLING   - Falling edge
*     - TimerHumidityTemp_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void TimerHumidityTemp_SetStartMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TimerHumidityTemp_TRIG_CONTROL1_REG &= (uint32)~TimerHumidityTemp_START_MASK;
    TimerHumidityTemp_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << TimerHumidityTemp_START_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_SetStopMode
********************************************************************************
*
* Summary:
*  Sets the stop trigger mode. For PWM mode this is the kill input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - TimerHumidityTemp_TRIG_LEVEL     - Level
*     - TimerHumidityTemp_TRIG_RISING    - Rising edge
*     - TimerHumidityTemp_TRIG_FALLING   - Falling edge
*     - TimerHumidityTemp_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void TimerHumidityTemp_SetStopMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TimerHumidityTemp_TRIG_CONTROL1_REG &= (uint32)~TimerHumidityTemp_STOP_MASK;
    TimerHumidityTemp_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << TimerHumidityTemp_STOP_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_SetCountMode
********************************************************************************
*
* Summary:
*  Sets the count trigger mode. For Quadrature Decoder mode this is the phiA
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - TimerHumidityTemp_TRIG_LEVEL     - Level
*     - TimerHumidityTemp_TRIG_RISING    - Rising edge
*     - TimerHumidityTemp_TRIG_FALLING   - Falling edge
*     - TimerHumidityTemp_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void TimerHumidityTemp_SetCountMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TimerHumidityTemp_TRIG_CONTROL1_REG &= (uint32)~TimerHumidityTemp_COUNT_MASK;
    TimerHumidityTemp_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << TimerHumidityTemp_COUNT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_TriggerCommand
********************************************************************************
*
* Summary:
*  Triggers the designated command to occur on the designated TCPWM instances.
*  The mask can be used to apply this command simultaneously to more than one
*  instance.  This allows multiple TCPWM instances to be synchronized.
*
* Parameters:
*  mask: A combination of mask bits for each instance of the TCPWM that the
*        command should apply to.  This function from one instance can be used
*        to apply the command to any of the instances in the design.
*        The mask value for a specific instance is available with the MASK
*        define.
*  command: Enumerated command values. Capture command only applicable for
*           Timer/Counter with Capture and PWM modes.
*   Values:
*     - TimerHumidityTemp_CMD_CAPTURE    - Trigger Capture/Switch command
*     - TimerHumidityTemp_CMD_RELOAD     - Trigger Reload/Index command
*     - TimerHumidityTemp_CMD_STOP       - Trigger Stop/Kill command
*     - TimerHumidityTemp_CMD_START      - Trigger Start/phiB command
*
* Return:
*  None
*
*******************************************************************************/
void TimerHumidityTemp_TriggerCommand(uint32 mask, uint32 command)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    TimerHumidityTemp_COMMAND_REG = ((uint32)(mask << command));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_ReadStatus
********************************************************************************
*
* Summary:
*  Reads the status of the TimerHumidityTemp.
*
* Parameters:
*  None
*
* Return:
*  Status
*   Values:
*     - TimerHumidityTemp_STATUS_DOWN    - Set if counting down
*     - TimerHumidityTemp_STATUS_RUNNING - Set if counter is running
*
*******************************************************************************/
uint32 TimerHumidityTemp_ReadStatus(void)
{
    return ((TimerHumidityTemp_STATUS_REG >> TimerHumidityTemp_RUNNING_STATUS_SHIFT) |
            (TimerHumidityTemp_STATUS_REG & TimerHumidityTemp_STATUS_DOWN));
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_SetInterruptMode
********************************************************************************
*
* Summary:
*  Sets the interrupt mask to control which interrupt
*  requests generate the interrupt signal.
*
* Parameters:
*   interruptMask: Mask of bits to be enabled
*   Values:
*     - TimerHumidityTemp_INTR_MASK_TC       - Terminal count mask
*     - TimerHumidityTemp_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void TimerHumidityTemp_SetInterruptMode(uint32 interruptMask)
{
    TimerHumidityTemp_INTERRUPT_MASK_REG =  interruptMask;
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_GetInterruptSourceMasked
********************************************************************************
*
* Summary:
*  Gets the interrupt requests masked by the interrupt mask.
*
* Parameters:
*   None
*
* Return:
*  Masked interrupt source
*   Values:
*     - TimerHumidityTemp_INTR_MASK_TC       - Terminal count mask
*     - TimerHumidityTemp_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 TimerHumidityTemp_GetInterruptSourceMasked(void)
{
    return (TimerHumidityTemp_INTERRUPT_MASKED_REG);
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_GetInterruptSource
********************************************************************************
*
* Summary:
*  Gets the interrupt requests (without masking).
*
* Parameters:
*  None
*
* Return:
*  Interrupt request value
*   Values:
*     - TimerHumidityTemp_INTR_MASK_TC       - Terminal count mask
*     - TimerHumidityTemp_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 TimerHumidityTemp_GetInterruptSource(void)
{
    return (TimerHumidityTemp_INTERRUPT_REQ_REG);
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_ClearInterrupt
********************************************************************************
*
* Summary:
*  Clears the interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to clear
*   Values:
*     - TimerHumidityTemp_INTR_MASK_TC       - Terminal count mask
*     - TimerHumidityTemp_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void TimerHumidityTemp_ClearInterrupt(uint32 interruptMask)
{
    TimerHumidityTemp_INTERRUPT_REQ_REG = interruptMask;
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_SetInterrupt
********************************************************************************
*
* Summary:
*  Sets a software interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to set
*   Values:
*     - TimerHumidityTemp_INTR_MASK_TC       - Terminal count mask
*     - TimerHumidityTemp_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void TimerHumidityTemp_SetInterrupt(uint32 interruptMask)
{
    TimerHumidityTemp_INTERRUPT_SET_REG = interruptMask;
}


/* [] END OF FILE */
