/*
 * ====================================================================================================================================
 *  Project		: Vehicle Door Handle Control Unit
 * 	File Name	: Led.h
 *	Team 		: 20
 *	Members		: Abdelrahman Yasser - Omar Ahmed Anwar - Mo'men Mohamed - Neveen Mohamed
 *  ===================================================================================================================================
 */

#ifndef LED_H_
#define LED_H_

/*---------------------- Includes ----------------------*/
#include "Gpio.h"
/*------------------------------------------------------*/

/*---------------------- Defined types ------------------*/
typedef enum{
	LED_OFF = LOW,
	LED_ON  = HIGH,
}LED_States;
/*--------------------------------------------------------*/

/*------------------ Functions Prototype -----------------*/

/*
 * description:
 * 	Argument(s):
 * 		--> portName:	LED Port.
 * 		--> pinNum: 	LED pin.
 * 	Function to configure Port and pin of the LED.
 */
void LED_Init(uint8 portName, uint8 pinNum);

/*
 * description:
 * 	Argument(s):
 * 		--> portName:	LED Port.
 * 		--> pinNum: 	LED pin.
 * 		--> state: 		Activate the led HIGH or LOW.
 * 	Function to activate the LED corresponding to the state.
 */
void LED_Activate(uint8 portName, uint8 pinNum, LED_States state);

/*
 * description:
 * 	Argument(s):
 * 		--> portName:	LED Port.
 * 		--> pinNum: 	LED pin.
 * 	Function to toggle the LED.
 */
void LED_Toggle(uint8 portName, uint8 pinNum);
/*--------------------------------------------------------------------*/

#endif /* LED_H_ */
