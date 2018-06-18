/*******************************************************************************
* File Name: HumidityTempIsr.h
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
#if !defined(CY_ISR_HumidityTempIsr_H)
#define CY_ISR_HumidityTempIsr_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void HumidityTempIsr_Start(void);
void HumidityTempIsr_StartEx(cyisraddress address);
void HumidityTempIsr_Stop(void);

CY_ISR_PROTO(HumidityTempIsr_Interrupt);

void HumidityTempIsr_SetVector(cyisraddress address);
cyisraddress HumidityTempIsr_GetVector(void);

void HumidityTempIsr_SetPriority(uint8 priority);
uint8 HumidityTempIsr_GetPriority(void);

void HumidityTempIsr_Enable(void);
uint8 HumidityTempIsr_GetState(void);
void HumidityTempIsr_Disable(void);

void HumidityTempIsr_SetPending(void);
void HumidityTempIsr_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the HumidityTempIsr ISR. */
#define HumidityTempIsr_INTC_VECTOR            ((reg32 *) HumidityTempIsr__INTC_VECT)

/* Address of the HumidityTempIsr ISR priority. */
#define HumidityTempIsr_INTC_PRIOR             ((reg32 *) HumidityTempIsr__INTC_PRIOR_REG)

/* Priority of the HumidityTempIsr interrupt. */
#define HumidityTempIsr_INTC_PRIOR_NUMBER      HumidityTempIsr__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable HumidityTempIsr interrupt. */
#define HumidityTempIsr_INTC_SET_EN            ((reg32 *) HumidityTempIsr__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the HumidityTempIsr interrupt. */
#define HumidityTempIsr_INTC_CLR_EN            ((reg32 *) HumidityTempIsr__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the HumidityTempIsr interrupt state to pending. */
#define HumidityTempIsr_INTC_SET_PD            ((reg32 *) HumidityTempIsr__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the HumidityTempIsr interrupt. */
#define HumidityTempIsr_INTC_CLR_PD            ((reg32 *) HumidityTempIsr__INTC_CLR_PD_REG)



#endif /* CY_ISR_HumidityTempIsr_H */


/* [] END OF FILE */
