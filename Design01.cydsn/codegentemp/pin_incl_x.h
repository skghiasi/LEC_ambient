/*******************************************************************************
* File Name: pin_incl_x.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_pin_incl_x_H) /* Pins pin_incl_x_H */
#define CY_PINS_pin_incl_x_H

#include "cytypes.h"
#include "cyfitter.h"
#include "pin_incl_x_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} pin_incl_x_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   pin_incl_x_Read(void);
void    pin_incl_x_Write(uint8 value);
uint8   pin_incl_x_ReadDataReg(void);
#if defined(pin_incl_x__PC) || (CY_PSOC4_4200L) 
    void    pin_incl_x_SetDriveMode(uint8 mode);
#endif
void    pin_incl_x_SetInterruptMode(uint16 position, uint16 mode);
uint8   pin_incl_x_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void pin_incl_x_Sleep(void); 
void pin_incl_x_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(pin_incl_x__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define pin_incl_x_DRIVE_MODE_BITS        (3)
    #define pin_incl_x_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - pin_incl_x_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the pin_incl_x_SetDriveMode() function.
         *  @{
         */
        #define pin_incl_x_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define pin_incl_x_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define pin_incl_x_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define pin_incl_x_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define pin_incl_x_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define pin_incl_x_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define pin_incl_x_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define pin_incl_x_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define pin_incl_x_MASK               pin_incl_x__MASK
#define pin_incl_x_SHIFT              pin_incl_x__SHIFT
#define pin_incl_x_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in pin_incl_x_SetInterruptMode() function.
     *  @{
     */
        #define pin_incl_x_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define pin_incl_x_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define pin_incl_x_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define pin_incl_x_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(pin_incl_x__SIO)
    #define pin_incl_x_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(pin_incl_x__PC) && (CY_PSOC4_4200L)
    #define pin_incl_x_USBIO_ENABLE               ((uint32)0x80000000u)
    #define pin_incl_x_USBIO_DISABLE              ((uint32)(~pin_incl_x_USBIO_ENABLE))
    #define pin_incl_x_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define pin_incl_x_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define pin_incl_x_USBIO_ENTER_SLEEP          ((uint32)((1u << pin_incl_x_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << pin_incl_x_USBIO_SUSPEND_DEL_SHIFT)))
    #define pin_incl_x_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << pin_incl_x_USBIO_SUSPEND_SHIFT)))
    #define pin_incl_x_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << pin_incl_x_USBIO_SUSPEND_DEL_SHIFT)))
    #define pin_incl_x_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(pin_incl_x__PC)
    /* Port Configuration */
    #define pin_incl_x_PC                 (* (reg32 *) pin_incl_x__PC)
#endif
/* Pin State */
#define pin_incl_x_PS                     (* (reg32 *) pin_incl_x__PS)
/* Data Register */
#define pin_incl_x_DR                     (* (reg32 *) pin_incl_x__DR)
/* Input Buffer Disable Override */
#define pin_incl_x_INP_DIS                (* (reg32 *) pin_incl_x__PC2)

/* Interrupt configuration Registers */
#define pin_incl_x_INTCFG                 (* (reg32 *) pin_incl_x__INTCFG)
#define pin_incl_x_INTSTAT                (* (reg32 *) pin_incl_x__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define pin_incl_x_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(pin_incl_x__SIO)
    #define pin_incl_x_SIO_REG            (* (reg32 *) pin_incl_x__SIO)
#endif /* (pin_incl_x__SIO_CFG) */

/* USBIO registers */
#if !defined(pin_incl_x__PC) && (CY_PSOC4_4200L)
    #define pin_incl_x_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define pin_incl_x_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define pin_incl_x_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define pin_incl_x_DRIVE_MODE_SHIFT       (0x00u)
#define pin_incl_x_DRIVE_MODE_MASK        (0x07u << pin_incl_x_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins pin_incl_x_H */


/* [] END OF FILE */
