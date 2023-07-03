/*
 * ====================================================================================================================================
 *  Project		: Vehicle Door Handle Control Unit
 * 	File Name	: Gpio.c
 *	Team 		: 20
 *	Members		: Abdelrahman Yasser - Omar Ahmed Anwar - Mo'men Mohamed - Neveen Mohamed
 *  ===================================================================================================================================
 */

/*---------------------- Includes ----------------------*/
#include "Gpio.h"
/*------------------------------------------------------*/

/*--------------- Global variables --------------------*/
uint32 gpioAddresses[5] = {GPIOA_BASE_ADDR,
						GPIOB_BASE_ADDR,
						GPIOC_BASE_ADDR,
						GPIOD_BASE_ADDR,
						GPIOE_BASE_ADDR};
/*------------------------------------------------------*/

/*---------------------- Functions Definition ----------------------*/

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
		Gpio_PinMode PinMode,Gpio_DefaultState DefaultState,
		Gpio_PullState pullState)
{

	uint8 portID = PortName - GPIO_A;

	GPIO_Reg *GPIO_Port = (GPIO_Reg *)gpioAddresses[portID];

	GPIO_Port->GPIOx_MODER &= ~(0x03 << (PinNum * 2));
	GPIO_Port->GPIOx_MODER |= (PinMode << (PinNum * 2));

	GPIO_Port->GPIOx_OTYPER &= ~(0x01 << PinNum);
	GPIO_Port->GPIOx_OTYPER |= (DefaultState << PinNum);

	GPIO_Port->GPIOx_PUPDR &= ~(0x03 << (PinNum * 2));
	GPIO_Port->GPIOx_PUPDR |= (pullState << (PinNum * 2));

}

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
		uint8 PinNum, Gpio_Data Data){

	uint8 portID = PortName - GPIO_A;

	GPIO_Reg *GPIO_Port = (GPIO_Reg *)gpioAddresses[portID];

	if (( (GPIO_Port->GPIOx_MODER) & (0x03 << (PinNum * 2))) >> (PinNum*2) != GPIO_OUTPUT)
	{
		return NOK;
	}

	if(Data == HIGH){
		GPIO_Port->GPIOx_ODR |= (Data << PinNum);
	}
	else {
		GPIO_Port->GPIOx_ODR &= ~(0x1 << PinNum);
	}

	return OK;
}

/*
 * description:
 * 	Argument(s):
 * 		--> PortName: Port needed to be configured.
 * 		--> PinNum: The pin needed to be configured.
 * 	Function to read data from the selected pin in the selected port.
 * 	Return:
 * 		--> Gpio_Data: Logic (High or Low).
 */
Gpio_Data GPIO_ReadPinState(uint8 PortName, uint8 PinNum){

	uint8 portID = PortName - GPIO_A;

	GPIO_Reg *GPIO_Port = (GPIO_Reg *)gpioAddresses[portID];

	Gpio_Data data;
	if ( ((GPIO_Port->GPIOx_MODER & (0x03 << (PinNum * 2))) >> (PinNum*2) ) == GPIO_OUTPUT) {
		data = ( (GPIO_Port->GPIOx_ODR) & (1 << PinNum))? GPIO_DATA_FALLING : GPIO_DATA_RISING;
	}
	else if ( ((GPIO_Port->GPIOx_MODER & (0x03 << (PinNum * 2))) >> (PinNum*2) ) == GPIO_INPUT){
		data = ( (GPIO_Port->GPIOx_IDR) & (1 << PinNum))? GPIO_DATA_RISING : GPIO_DATA_FALLING;
	}
	return data;
}
/*------------------------------------------------------*/





