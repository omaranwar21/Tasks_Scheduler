/*
 * ====================================================================================================================================
 *  Project		: Vehicle Door Handle Control Unit
 * 	File Name	: Delay.c
 *	Team 		: 20
 *	Members		: Abdelrahman Yasser - Omar Ahmed Anwar - Mo'men Mohamed - Neveen Mohamed
 *  ===================================================================================================================================
 */

/*---------------------- Includes ----------------------*/
#include "Delay.h" // header file of the delay
/*------------------------------------------------------*/


/*---------------------- Functions Definition ----------------------*/
/*
 * Description:
 * 	Argument(s): time needed in millisecond
 */
void delay_ms(uint32 time)
{
	float32 t_cycle = 1.0 / 1000000;

    uint32 delay = time / (t_cycle * 1000);

    uint32 loop;

    for (loop = 0; loop < delay; loop++);
}
/*------------------------------------------------------*/
