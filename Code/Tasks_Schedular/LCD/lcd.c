/*
 * ====================================================================================================================================
 *  Module		: LCD driver
 * 	File Name	: lcd.c
 *	Author		: Omar Ahmed Anwar
 *  ===================================================================================================================================
 */

#include "Delay.h" /* For the delay functions */
#include "Bit_Operations.h" /* For READ_BIT Macro */
#include "lcd.h"
#include "Gpio.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions by use the GPIO driver.
 * 2. Setup the LCD Data Mode 4-bits or 8-bits.
 */
void LCD_init(void)
{

	/* Configure the direction for RS and E pins as output pins */
	Gpio_ConfigPin(LCD_RS_PORT_ID, LCD_RS_PIN_ID, GPIO_OUTPUT, GPIO_PUSH_PULL, GPIO_NO_PULL_UP_DOWN);
	Gpio_ConfigPin(LCD_E_PORT_ID, LCD_E_PIN_ID, GPIO_OUTPUT, GPIO_PUSH_PULL, GPIO_NO_PULL_UP_DOWN);
	delay_ms(20);		/* LCD Power ON delay always > 15ms */

#if(LCD_DATA_BITS_MODE == 4)
	/* Configure 4 pins in the data port as output pins */
	Gpio_ConfigPin(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID, GPIO_OUTPUT, GPIO_PUSH_PULL, GPIO_NO_PULL_UP_DOWN);
	Gpio_ConfigPin(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID, GPIO_OUTPUT, GPIO_PUSH_PULL, GPIO_NO_PULL_UP_DOWN);
	Gpio_ConfigPin(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID, GPIO_OUTPUT, GPIO_PUSH_PULL, GPIO_NO_PULL_UP_DOWN);
	Gpio_ConfigPin(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID, GPIO_OUTPUT, GPIO_PUSH_PULL, GPIO_NO_PULL_UP_DOWN);

	/* Send for 4 bit initialization of LCD  */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT1);
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT2);

	/* use 2-lines LCD + 4-bits Data Mode + 5*7 dot display Mode */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE);

#elif(LCD_DATA_BITS_MODE == 8)
	/* Configure the data port as output port */
	uint8 counter = 0;
	for (counter = LCD_DATA_PIN_ID; counter < (LCD_DATA_PIN_ID+LCD_DATA_BITS_MODE) ; ++counter) {
		Gpio_ConfigPin(LCD_DATA_PORT_ID, counter, GPIO_OUTPUT, GPIO_PUSH_PULL, GPIO_NO_PULL_UP_DOWN);
	}

	/* use 2-lines LCD + 8-bits Data Mode + 5*7 dot display Mode */
	LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);

#endif

	LCD_sendCommand(LCD_CURSOR_OFF); /* cursor off */
	LCD_sendCommand(LCD_CLEAR_COMMAND); /* clear LCD at the beginning */
}

/*
 * Description :
 * Send the required command to the screen
 */
void LCD_sendCommand(uint8 command)
{

	GPIO_WritePinValue(LCD_RS_PORT_ID,LCD_RS_PIN_ID,LOW); /* Instruction Mode RS=0 */
	delay_ms(1); /* delay for processing Tas = 50ns */
	GPIO_WritePinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,HIGH); /* Enable LCD E=1 */
	delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

#if(LCD_DATA_BITS_MODE == 4)
	GPIO_WritePinValue(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,READ_BIT(command,4));
	GPIO_WritePinValue(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,READ_BIT(command,5));
	GPIO_WritePinValue(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,READ_BIT(command,6));
	GPIO_WritePinValue(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,READ_BIT(command,7));

	delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_WritePinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,LOW); /* Disable LCD E=0 */
	delay_ms(1); /* delay for processing Th = 13ns */
	GPIO_WritePinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,HIGH); /* Enable LCD E=1 */
	delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

	GPIO_WritePinValue(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,READ_BIT(command,0));
	GPIO_WritePinValue(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,READ_BIT(command,1));
	GPIO_WritePinValue(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,READ_BIT(command,2));
	GPIO_WritePinValue(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,READ_BIT(command,3));

	delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_WritePinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,LOW); /* Disable LCD E=0 */
	delay_ms(1); /* delay for processing Th = 13ns */

#elif(LCD_DATA_BITS_MODE == 8)

	uint8 counter = 0;
	for (counter = 0; counter < 8 ; ++counter) {
		Gpio_ConfigPin(LCD_DATA_PORT_ID, counter, GPIO_OUTPUT, GPIO_PUSH_PULL, GPIO_NO_PULL_UP_DOWN);
		GPIO_WritePinValue(LCD_DATA_PORT_ID, counter, READ_BIT(command, counter));
	}
	//	GPIO_writePort(LCD_DATA_PORT_ID,command); /* out the required command to the data bus D0 --> D7 */
	delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_WritePinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,LOW); /* Disable LCD E=0 */
	delay_ms(1); /* delay for processing Th = 13ns */
#endif
}

/*
 * Description :
 * Display the required character on the screen
 */
void LCD_displayCharacter(uint8 data)
{

	GPIO_WritePinValue(LCD_RS_PORT_ID,LCD_RS_PIN_ID,HIGH); /* Data Mode RS=1 */
//	delay_ms(1); /* delay for processing Tas = 50ns */
	GPIO_WritePinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,HIGH); /* Enable LCD E=1 */
//	delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

#if(LCD_DATA_BITS_MODE == 4)
	GPIO_WritePinValue(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,READ_BIT(data,4));
	GPIO_WritePinValue(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,READ_BIT(data,5));
	GPIO_WritePinValue(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,READ_BIT(data,6));
	GPIO_WritePinValue(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,READ_BIT(data,7));

	delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_WritePinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,LOW); /* Disable LCD E=0 */
	delay_ms(1); /* delay for processing Th = 13ns */
	GPIO_WritePinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,HIGH); /* Enable LCD E=1 */
	delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

	GPIO_WritePinValue(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,READ_BIT(data,0));
	GPIO_WritePinValue(LCD_DATA_PORT_ID,LCD_DB5_PIN_ID,READ_BIT(data,1));
	GPIO_WritePinValue(LCD_DATA_PORT_ID,LCD_DB6_PIN_ID,READ_BIT(data,2));
	GPIO_WritePinValue(LCD_DATA_PORT_ID,LCD_DB7_PIN_ID,READ_BIT(data,3));

	delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_WritePinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,LOW); /* Disable LCD E=0 */
	delay_ms(1); /* delay for processing Th = 13ns */

#elif(LCD_DATA_BITS_MODE == 8)
	uint8 counter = 0;
	for (counter = 0; counter < 8 ; ++counter) {
		Gpio_ConfigPin(LCD_DATA_PORT_ID, counter, GPIO_OUTPUT, GPIO_PUSH_PULL, GPIO_NO_PULL_UP_DOWN);
		GPIO_WritePinValue(LCD_DATA_PORT_ID, counter, READ_BIT(data, counter));
	}
//	GPIO_writePort(LCD_DATA_PORT_ID,data); /* out the required command to the data bus D0 --> D7 */
//	delay_ms(1); /* delay for processing Tdsw = 100ns */
	GPIO_WritePinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,LOW); /* Disable LCD E=0 */
//	delay_ms(1); /* delay for processing Th = 13ns */
#endif
}

/*
 * Description :
 * Display the required string on the screen
 */
void LCD_displayString(const char *Str)
{
	uint8 i = 0;
	while(Str[i] != '\0')
	{
		LCD_displayCharacter(Str[i]);
		i++;
	}
	/***************** Another Method ***********************
	while((*Str) != '\0')
	{
		LCD_displayCharacter(*Str);
		Str++;
	}		
	 *********************************************************/
}

/*
 * Description :
 * Move the cursor to a specified row and column index on the screen
 */
void LCD_moveCursor(uint8 row,uint8 col)
{
	uint8 lcd_memory_address;

	/* Calculate the required address in the LCD DDRAM */
	switch(row)
	{
	case 0:
		lcd_memory_address=col;
		break;
	case 1:
		lcd_memory_address=col+0x40;
		break;
	case 2:
		lcd_memory_address=col+0x10;
		break;
	case 3:
		lcd_memory_address=col+0x50;
		break;
	}					
	/* Move the LCD cursor to this specific address */
	LCD_sendCommand(lcd_memory_address | LCD_SET_CURSOR_LOCATION);
}

/*
 * Description :
 * Display the required string in a specified row and column index on the screen
 */
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str)
{
	LCD_moveCursor(row,col); /* go to to the required LCD position */
	LCD_displayString(Str); /* display the string */
}

/*
 * Description :
 * Display the required decimal value on the screen
 */
void LCD_intgerToString(int data)
{
	char buff[16]; /* String to hold the ascii result */
	itoa(data,buff,10); /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
	LCD_displayString(buff); /* Display the string */
}

/*
 * Description :
 * Send the clear screen command
 */
void LCD_clearScreen(void)
{
	LCD_sendCommand(LCD_CLEAR_COMMAND); /* Send clear display command */
	LCD_moveCursor(0, 0);
}
