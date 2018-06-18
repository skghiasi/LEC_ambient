/*******************************************************************************
* File Name: TimerHumidityTemp_PM.c
* Version 2.10
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
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

static TimerHumidityTemp_BACKUP_STRUCT TimerHumidityTemp_backup;


/*******************************************************************************
* Function Name: TimerHumidityTemp_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void TimerHumidityTemp_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: TimerHumidityTemp_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void TimerHumidityTemp_Sleep(void)
{
    if(0u != (TimerHumidityTemp_BLOCK_CONTROL_REG & TimerHumidityTemp_MASK))
    {
        TimerHumidityTemp_backup.enableState = 1u;
    }
    else
    {
        TimerHumidityTemp_backup.enableState = 0u;
    }

    TimerHumidityTemp_Stop();
    TimerHumidityTemp_SaveConfig();
}


/*******************************************************************************
* Function Name: TimerHumidityTemp_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void TimerHumidityTemp_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: TimerHumidityTemp_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void TimerHumidityTemp_Wakeup(void)
{
    TimerHumidityTemp_RestoreConfig();

    if(0u != TimerHumidityTemp_backup.enableState)
    {
        TimerHumidityTemp_Enable();
    }
}


/* [] END OF FILE */
