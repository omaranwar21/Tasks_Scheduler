/*
 * ====================================================================================================================================
 *  Project		: Vehicle Door Handle Control Unit
 * 	File Name	: Gpio.h
 *	Team 		: 20
 *	Members		: Abdelrahman Yasser - Omar Ahmed Anwar - Mo'men Mohamed - Neveen Mohamed
 *  ===================================================================================================================================
 */

#ifndef GPIO_H
#define GPIO_H

/*---------------------- Includes ----------------------*/
#include "Gpio_Private.h"
#include "Utils.h"
/*------------------------------------------------------*/

/*--------------------- Definitions -------------------- */
#define GPIO_A 'A'
#define GPIO_B 'B'
#define GPIO_C 'C'
#define GPIO_D 'D'

#define GPIO_DATA_FALLING	1
#define GPIO_DATA_RISING	0
/*------------------------------------------------------*/

/*----------------- Defined types ----------------------*/
/*PinMode*/
typedef enum{
   GPIO_INPUT, GPIO_OUTPUT, GPIO_AF, GPIO_ANALOG 
}Gpio_PinMode;

/*DefaultState*/
typedef enum{
   GPIO_PUSH_PULL, GPIO_OPEN_DRAIN 
}Gpio_DefaultState;

/*Data*/
typedef enum{
   LOW, HIGH 
}Gpio_Data;

/*Flag*/
typedef enum{
    NOK, OK
}Gpio_WriteDataFlag;

/*Pull up, Pull down*/
typedef enum{
	GPIO_NO_PULL_UP_DOWN, GPIO_PULL_UP,
	GPIO_PULL_DOWN, GPIO_RESERVED
}Gpio_PullState;
/*------------------------------------------------------*/

/*---------------------- Functions Prototype ----------------------*/

/*
 * description:
 * 	Argument(s):
 * 		--> PortName: Port needed to be configured.
 * 		--> PinNum: The pin needed to be configured.
 * 		--> PinMode: Modeof the Pin (Output, Input, Alternative function
 * 					 or Analog).
 * 		--> DefaultState: state of the pin whether being push/pull or
 * 						  open drain.
 * 		--> pullState: state of the pin (no pull up/down, pull up, pull down,
 * 					   or Reserved).
 * 	Function to configure the selected pin in the selected port.
 */
void Gpio_ConfigPin(uint8 PortName, uint8 PinNum,
		Gpio_PinMode PinMode, Gpio_DefaultState DefaultState,
		Gpio_PullState pullState);

/*
 * description:
 * 	Argument(s):
 * 		--> PortName: Port needed to be configured.
 * 		--> PinNum: The pin needed to be configured.
 * 		--> Data: data is wanted to be written (High or Low).
 * 	Function to write data on the selected pin in the selected port.
 * 	Return:
 * 		--> Gpio_WriteDataFlag: data has been written successfully or not
 * 								(OK or NOK)
 * 								if the pin was output --> OK.
 * 								if the pin was input  --> NOK
 */
Gpio_WriteDataFlag GPIO_WritePinValue(uint8 PortName,
		uint8 PinNum,Gpio_Data Data);

/*
 * description:
 * 	Argument(s):
 * 		--> PortName: Port needed to be configured.
 * 		--> PinNum: The pin needed to be configured.
 * 	Function to read data from the selected pin in the selected port.
 * 	Return:
 * 		--> Gpio_Data: Logic (High or Low).
 */
Gpio_Data GPIO_ReadPinState(uint8 PortName, uint8 PinNum);
/*--------------------------------------------------------------------*/

#endif /* GPIO_H */
