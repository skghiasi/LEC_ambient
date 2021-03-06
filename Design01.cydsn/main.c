/******************************************************************************
* File Name: main.c
*
* Version 1.30
*
* Description: 
*  This code example demonstrates basic usage of PSoC 4 Serial Communication 
*  Block (SCB) Component in I2C Master mode. This project implements the 
*  I2C Master device, which sends commands to I2C Slave device and reads 
*  status of the command execution: success or error. Result or command 
*  execution shown using RGB LED: green for success and red for error.
*
* Related Document: 
*  CE222306_PSoC4_I2C_SCB.pdf
*
* Hardware Dependency: 
*  See CE222306_PSoC4_I2C_SCB.pdf
*
*******************************************************************************
* Copyright (2018), Cypress Semiconductor Corporation. All rights reserved.
*******************************************************************************
* This software, including source code, documentation and related materials
* ("Software"), is owned by Cypress Semiconductor Corporation or one of its
* subsidiaries ("Cypress") and is protected by and subject to worldwide patent
* protection (United States and foreign), United States copyright laws and
* international treaty provisions. Therefore, you may use this Software only
* as provided in the license agreement accompanying the software package from
* which you obtained this Software ("EULA").
*
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software source
* code solely for use in connection with Cypress’s integrated circuit products.
* Any reproduction, modification, translation, compilation, or representation
* of this Software except as specified above is prohibited without the express
* written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND, 
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED 
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress 
* reserves the right to make changes to the Software without notice. Cypress 
* does not assume any liability arising out of the application or use of the 
* Software or any product or circuit described in the Software. Cypress does 
* not authorize its products for use in any products where a malfunction or 
* failure of the Cypress product may reasonably be expected to result in 
* significant property damage, injury or death ("High Risk Product"). By 
* including Cypress’s product in a High Risk Product, the manufacturer of such 
* system or application assumes all risk of such use and in doing so agrees to 
* indemnify Cypress against all liability. 
*******************************************************************************/

#include "main.h"
#include "stdio.h"
#include <project.h>

#include <ADC_SAR_SEQ.h>

#define TIMER_CLK_FREQ 1000


#define CH0_N               (0x00u)
#define CH1_N               (0x01u)
#define TEMP_CH             (0x01u)
#define DELAY_1SEC          (1000u)

/* Get actual Vref. value from ADC SAR sequencer */
//#define ADC_VREF_VALUE_V    ((float)ADC_SAR_SEQ_DEFAULT_VREF_MV_VALUE/1000.0)

volatile uint32 dataReady = 0u;
volatile int16 result[ADC_SAR_SEQ_TOTAL_CHANNELS_NUM];
volatile uint32 timer_delay = 0u;


/*******************************************************************************
* Function Name: WriteCommandPacket
********************************************************************************
* 
* Summary:
*  Master initiates the transfer to write command packet into the slave.
*  The status of the transfer is returned.
*
* Parameters:
*  cmd: command to execute. Supported commands:
*   - CMD_SET_RED:   set red color of the LED.
*   - CMD_SET_GREEN: set green color of the LED.
*   - CMD_SET_BLUE:  set blue color of the LED.
*   - CMD_SET_OFF:   turn off the LED.
*
* Return:
*  Status of the data transfer. There are two statuses
*  - TRANSFER_CMPLT: transfer completed successfully.
*  - TRANSFER_ERROR: the error occurred while transfer.
*
*******************************************************************************/
/* global definitions */ 




void UART_printFormat(int temp , int humid){
    char a [50]; 
    sprintf( a, "Temperature: %d, Humidity: %d\n", temp, humid); 
    UART_UartPutString(a);
}
uint32 WriteCommandPacket(uint8 cmd)
{
    uint8  buffer[BUFFER_SIZE]; 
    uint32 status = TRANSFER_ERROR;
    buffer[BUFFER_SIZE-1] = cmd; 
    /* Initialize buffer with packet */
   

    (void) I2CM_I2CMasterClearStatus();
    
    /* Start I2C write and check status*/
    if(I2CM_I2C_MSTR_NO_ERROR == I2CM_I2CMasterWriteBuf(I2C_SLAVE_ADDR,
                                    buffer, PACKET_SIZE,
                                    I2CM_I2C_MODE_COMPLETE_XFER))
    {
         
        /*If I2C write started without errors, 
        / wait until I2C Master completes write transfer 
        */
        while (0u == (I2CM_I2CMasterStatus() & I2CM_I2C_MSTAT_WR_CMPLT))
        {
            /* Wait */
        }
        
        /* Display transfer status */
        if (0u == (I2CM_I2CMasterStatus() & I2CM_I2C_MSTAT_ERR_XFER))
        {
            /* Check if all bytes was written */
            if (I2CM_I2CMasterGetWriteBufSize() == BUFFER_SIZE)
            {
                status = TRANSFER_CMPLT;
            }
        }
    }

    return (status);
}

/*******************************************************************************
* Function Name: ReadStatusPacket
********************************************************************************
* 
* Summary:
*  Master initiates the transfer to read status packet from the Slave.
*  The status of the transfer is returned.
*
* Parameters:
*  None
*
* Return:
*  Status of the transfer. There are two statuses
*  - TRANSFER_CMPLT: transfer completed successfully.
*  - TRANSFER_ERROR: the error occurred while transfer.
*
*******************************************************************************/
uint32 readSensor(uint8 cmd)
{
    WriteCommandPacket(cmd); 
    
    uint8  buffer[RECEIVE_BUFFER_SIZE];
    //uint32 status = TRANSFER_ERROR;
    uint32 value = 0 ; 
    
    (void) I2CM_I2CMasterClearStatus();
    
    if(I2CM_I2C_MSTR_NO_ERROR ==  I2CM_I2CMasterReadBuf(I2C_SLAVE_ADDR,
                                    buffer, RECEIVE_PACKET_SIZE,
                                    I2CM_I2C_MODE_COMPLETE_XFER))
    {
        /* If I2C read started without errors, 
        / wait until master complete read transfer */
        while (0u == (I2CM_I2CMasterStatus() & I2CM_I2C_MSTAT_RD_CMPLT))
        {
            /* Wait */
        }
        
        /* Display transfer status */
        //if (0u == (I2CM_I2C_MSTAT_ERR_XFER & I2CM_I2CMasterStatus()))
        //{     
        //    }
            
                value = buffer[0] << 8; 
                value += buffer[1]; 
                value &= ~0x0003; 
              
        }
   

    return (value);
}

float getTemperature(){
    return (-46.85 + 175.72 / 65536.0 * (float)(readSensor(eTempHoldCmd)));    
}

float getHumidity(){
    return (-6.0 + 125.0 / 65536.0 * (float)(readSensor(eRHumidityCmd))); 
}

void runTempHumidModule(){
        uint32 humid = 0 ; 
        uint32 temperature = 0; 
        humid = getHumidity();
        temperature = getTemperature(); 
        
        UART_printFormat(temperature , humid); 
}



/************************************************************
*function Block: Timer Counter related
*************************************************************/
//void printRPM(int input){
    //char a [50]; 
    //sprintf(a , "rpm: %d\n", input); 
    //UART_UartPutString(a); 
//}

/*CY_ISR(Ctr_Function)
{
    uint32 counter ;
    float data = 0 ; 
    counter = Timer_ReadCounter();  // Read counter value
    Timer_WriteCounter(0u);         // Reset counter to zero
    InputPin_ClearInterrupt();
    
    data = counter;    // fill array  with values
    //printRPM(counter); 
    data = data * 0.001; 
    if(data != 0)
        data = 1 / data; 
    //find rpm (three propellors) 
    data = data * 60 / 3; 
    if (data < MAX_TURBINE_RPM && data >= 0) 
        printRPM(data); 
}*/

/** period function to reduce the communication rate of sensors */ 
CY_ISR(Period_function)
{
    TimerHumidityTemp_ClearInterrupt(Timer_INTR_MASK_TC);
    //printRPM(1000);
    //runTempHumidModule(); 
}


CY_ISR(ADC_SAR_SEQ_ISR_LOC)
{
    uint32 intr_status;
    uint32 range_status;

    /* Read interrupt status registers */
    intr_status = ADC_SAR_SEQ_SAR_INTR_MASKED_REG;
    /* Check for End of Scan interrupt */
    if((intr_status & ADC_SAR_SEQ_EOS_MASK) != 0u)
    {
        /* Read range detect status */
        range_status = ADC_SAR_SEQ_SAR_RANGE_INTR_MASKED_REG;
        /* Verify that the conversion result met the condition Low_Limit <= Result < High_Limit  */
        if((range_status & (uint32)(1ul << CH0_N)) != 0u) 
        {
            /* Read conversion result */
            result[CH0_N] = ADC_SAR_SEQ_GetResult16(CH0_N);
        }    
        
        if((range_status & (uint32)(1ul << CH1_N)) != 0u) 
        {
            /* Read conversion result */
            result[CH1_N] = ADC_SAR_SEQ_GetResult16(CH1_N);
        }    

        /* Clear range detect status */
        ADC_SAR_SEQ_SAR_RANGE_INTR_REG = range_status;
        dataReady |= ADC_SAR_SEQ_EOS_MASK;
    }    

   

    /* Clear handled interrupt */
    ADC_SAR_SEQ_SAR_INTR_REG = intr_status;
}


/*******************************************************************************
* Function Name: main
********************************************************************************
* 
* Summary:
*  This function:
*   1. Turns off the RGB LED.
*   2. Starts the I2C Master Component.
*   3. Enables global interrupts.
*   4. Sends command and reads status packets from the Slave every 500mS.
*
*******************************************************************************/
int main()
{
    CyGlobalIntEnable;
    
    float32 angle_y = 0 ; 
    float32 angle_x = 0 ; 
    char  uartLine[250];
    
    /* Start the I2C Master */
    I2CM_Start();
    UART_Start(); 
    Timer_Start();
    //TimerHumidityTemp_Start(); 
    
     /* Init and start sequencing SAR ADC */
    ADC_SAR_SEQ_Start();
    ADC_SAR_SEQ_StartConvert();
    /* Enable interrupt and set interrupt handler to local routine */
    ADC_SAR_SEQ_IRQ_StartEx(ADC_SAR_SEQ_ISR_LOC);
    
    //InputPinIsr_StartEx(Ctr_Function);
    //HumidityTempIsr_StartEx(Period_function); 
    
    for(;;)
    {      
        runTempHumidModule(); 
        
        CyDelay(CMD_TO_CMD_DELAY);       
         
        
        /* When conversion of sequencing channels has completed */
        if((dataReady & ADC_SAR_SEQ_EOS_MASK) != 0u)
        {
            /* Get voltage, measured by ADC */
            dataReady &= ~ADC_SAR_SEQ_EOS_MASK;
           
            angle_y = ADC_SAR_SEQ_CountsTo_Volts(CH0_N, result[CH0_N]);
            angle_x = ADC_SAR_SEQ_CountsTo_Volts(CH1_N, result[CH1_N]);
            
              
     
            
            /* Print voltage value to UART */
            sprintf(
                uartLine, "voltage_y: %f V, voltage_x %f\n",
                (float32)angle_y,(float32)angle_x
                );
            
            UART_UartPutString(uartLine);

        }
    }
}


/* [] END OF FILE */
