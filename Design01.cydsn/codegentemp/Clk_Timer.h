/*******************************************************************************
* File Name: Clk_Timer.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_Clk_Timer_H)
#define CY_CLOCK_Clk_Timer_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void Clk_Timer_StartEx(uint32 alignClkDiv);
#define Clk_Timer_Start() \
    Clk_Timer_StartEx(Clk_Timer__PA_DIV_ID)

#else

void Clk_Timer_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void Clk_Timer_Stop(void);

void Clk_Timer_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 Clk_Timer_GetDividerRegister(void);
uint8  Clk_Timer_GetFractionalDividerRegister(void);

#define Clk_Timer_Enable()                         Clk_Timer_Start()
#define Clk_Timer_Disable()                        Clk_Timer_Stop()
#define Clk_Timer_SetDividerRegister(clkDivider, reset)  \
    Clk_Timer_SetFractionalDividerRegister((clkDivider), 0u)
#define Clk_Timer_SetDivider(clkDivider)           Clk_Timer_SetDividerRegister((clkDivider), 1u)
#define Clk_Timer_SetDividerValue(clkDivider)      Clk_Timer_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define Clk_Timer_DIV_ID     Clk_Timer__DIV_ID

#define Clk_Timer_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define Clk_Timer_CTRL_REG   (*(reg32 *)Clk_Timer__CTRL_REGISTER)
#define Clk_Timer_DIV_REG    (*(reg32 *)Clk_Timer__DIV_REGISTER)

#define Clk_Timer_CMD_DIV_SHIFT          (0u)
#define Clk_Timer_CMD_PA_DIV_SHIFT       (8u)
#define Clk_Timer_CMD_DISABLE_SHIFT      (30u)
#define Clk_Timer_CMD_ENABLE_SHIFT       (31u)

#define Clk_Timer_CMD_DISABLE_MASK       ((uint32)((uint32)1u << Clk_Timer_CMD_DISABLE_SHIFT))
#define Clk_Timer_CMD_ENABLE_MASK        ((uint32)((uint32)1u << Clk_Timer_CMD_ENABLE_SHIFT))

#define Clk_Timer_DIV_FRAC_MASK  (0x000000F8u)
#define Clk_Timer_DIV_FRAC_SHIFT (3u)
#define Clk_Timer_DIV_INT_MASK   (0xFFFFFF00u)
#define Clk_Timer_DIV_INT_SHIFT  (8u)

#else 

#define Clk_Timer_DIV_REG        (*(reg32 *)Clk_Timer__REGISTER)
#define Clk_Timer_ENABLE_REG     Clk_Timer_DIV_REG
#define Clk_Timer_DIV_FRAC_MASK  Clk_Timer__FRAC_MASK
#define Clk_Timer_DIV_FRAC_SHIFT (16u)
#define Clk_Timer_DIV_INT_MASK   Clk_Timer__DIVIDER_MASK
#define Clk_Timer_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_Clk_Timer_H) */

/* [] END OF FILE */
