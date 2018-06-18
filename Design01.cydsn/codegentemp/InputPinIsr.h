/*******************************************************************************
* File Name: InputPinIsr.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_InputPinIsr_H)
#define CY_ISR_InputPinIsr_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void InputPinIsr_Start(void);
void InputPinIsr_StartEx(cyisraddress address);
void InputPinIsr_Stop(void);

CY_ISR_PROTO(InputPinIsr_Interrupt);

void InputPinIsr_SetVector(cyisraddress address);
cyisraddress InputPinIsr_GetVector(void);

void InputPinIsr_SetPriority(uint8 priority);
uint8 InputPinIsr_GetPriority(void);

void InputPinIsr_Enable(void);
uint8 InputPinIsr_GetState(void);
void InputPinIsr_Disable(void);

void InputPinIsr_SetPending(void);
void InputPinIsr_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the InputPinIsr ISR. */
#define InputPinIsr_INTC_VECTOR            ((reg32 *) InputPinIsr__INTC_VECT)

/* Address of the InputPinIsr ISR priority. */
#define InputPinIsr_INTC_PRIOR             ((reg32 *) InputPinIsr__INTC_PRIOR_REG)

/* Priority of the InputPinIsr interrupt. */
#define InputPinIsr_INTC_PRIOR_NUMBER      InputPinIsr__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable InputPinIsr interrupt. */
#define InputPinIsr_INTC_SET_EN            ((reg32 *) InputPinIsr__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the InputPinIsr interrupt. */
#define InputPinIsr_INTC_CLR_EN            ((reg32 *) InputPinIsr__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the InputPinIsr interrupt state to pending. */
#define InputPinIsr_INTC_SET_PD            ((reg32 *) InputPinIsr__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the InputPinIsr interrupt. */
#define InputPinIsr_INTC_CLR_PD            ((reg32 *) InputPinIsr__INTC_CLR_PD_REG)



#endif /* CY_ISR_InputPinIsr_H */


/* [] END OF FILE */
