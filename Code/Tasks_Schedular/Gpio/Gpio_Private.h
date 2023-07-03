/*
 * ====================================================================================================================================
 *  Project		: Vehicle Door Handle Control Unit
 * 	File Name	: Gpio_Private.h
 *	Team 		: 20
 *	Members		: Abdelrahman Yasser - Omar Ahmed Anwar - Mo'men Mohamed - Neveen Mohamed
 *  ===================================================================================================================================
 */

#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

/*---------------------- Includes ----------------------*/
#include "Std_Types.h" // to use standard types such as (uint32)
/*------------------------------------------------------*/

/*--------------------- Definitions -------------------- */
#define GPIOA_BASE_ADDR		0x40020000
#define GPIOB_BASE_ADDR		0x40020400
#define GPIOC_BASE_ADDR		0x40020800
#define GPIOD_BASE_ADDR		0x40020C00
#define GPIOE_BASE_ADDR		0x40021000
/*------------------------------------------------------*/

/*---------------------- defined data types --------------- */
typedef struct{
	uint32 GPIOx_MODER;
	uint32 GPIOx_OTYPER;
	uint32 GPIOx_OSPEEDR;
	uint32 GPIOx_PUPDR;
	uint32 GPIOx_IDR;
	uint32 GPIOx_ODR;
	uint32 GPIOx_BSRR;
	uint32 GPIOx_LCKR;
	uint32 GPIOx_AFRL;
	uint32 GPIOx_AFRH;
}GPIO_Reg;
/*-------------------------------------------------------------*/

#endif /* GPIO_PRIVATE_H */
