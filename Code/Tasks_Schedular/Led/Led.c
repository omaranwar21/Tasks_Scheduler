/*
 * ====================================================================================================================================
 *  Project		: Vehicle Door Handle Control Unit
 * 	File Name	: Led.c
 *	Team 		: 20
 *	Members		: Abdelrahman Yasser - Omar Ahmed Anwar - Mo'men Mohamed - Neveen Mohamed
 *  ===================================================================================================================================
 */

/*---------------------- Includes ----------------------*/
#include "Led.h"
/*------------------------------------------------------*/

/*---------------------- Functions Definition ----------------------*/

/*
 * description:
 * 	Argument(s):
 * 		--> portName:	LED Port.
 * 		--> pinNum: 	LED pin.
 * 	Function to configure Port and pin of the LED.
 */
void LED_Init(uint8 portName, uint8 pinNum){

	Gpio_ConfigPin(portName, pinNum, GPIO_OUTPUT, GPIO_PUSH_PULL, GPIO_NO_PULL_UP_DOWN);

	GPIO_WritePinValue(portName, pinNum, (Gpio_Data)LED_OFF);
}

/*
 * description:
 * 	Argument(s):
 * 		--> portName:	LED Port.
 * 		--> pinNum: 	LED pin.
 * 		--> state: 		Activate the led HIGH or LOW.
 * 	Function to activate the LED corresponding to the state.
 */
void LED_Activate(uint8 portName, uint8 pinNum, LED_States state){

	GPIO_WritePinValue(portName, pinNum, (Gpio_Data)state);

}

/*
 * description:
 * 	Argument(s):
 * 		--> portName:	LED Port.
 * 		--> pinNum: 	LED pin.
 * 	Function to toggle the LED.
 */
void LED_Toggle(uint8 portName, uint8 pinNum){

	LED_States state = (LED_States)GPIO_ReadPinState(portName, pinNum);

	GPIO_WritePinValue(portName, pinNum, (Gpio_Data)!state);

}
/*-----------------------------------------------------------------------------*/



