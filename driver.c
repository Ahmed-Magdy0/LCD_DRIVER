/*
 * driver.c
 *
 *  Created on: Apr 18, 2019
 *      Author: Ahmed Magdy
 */

/*
 * File description: this file includes all source functions for the driver implementation.
 *
 */
#include "APIS.h"
#include "tm4c123gh6pm.h"
#include "stdbool.h"
#include "stdint.h"
#include "driver.h"
#include "stdlib.h"


/*
 * Description: this function is used for initializing the LCD(2*16) driver
 *
 * pre:1-you have to choose your target and connect it to the device.
 *     2-you have to connect your data pins to the target and it must be at the same port.
 *     3-Delay_ms() , Sys() and LCD_sendCommand() are declared.
 *
 * post: the driver is initialized and ready to be used.
*/
void Driver_Initi(void)
{
	GPIO_CLK_CTRL_R |= CLK_ENABL;                      //Enable clk for portA and PortB
	LCD_CTRL_DIR_R  |= (RS|RW|E);                     //use RS,RW and E output pins
	LCD_CTRL_DEN_R  |= (RS|RW|E);                     //use RS,RW and E digital pins
	LCD_DATA_DIR_R  = DATA_ENABLE;                   //use Data port as output
	LCD_DATA_DEN_R  = DATA_ENABLE;                  //use Data port as output
	LCD_sendCommand(0x30);
	LCD_sendCommand(TWO_LINES_LCD_Eight_BIT_MODE);
	LCD_sendCommand(INCREMENT_CURSOR);
	LCD_sendCommand(CLEAR_SCREEN);
	LCD_sendCommand(CURSOR_BLINKING);
}


void LCD_sendCommand(uint8_t command)
{
	CLEAR_BIT(LCD_CTRL_PORT,RS);
	CLEAR_BIT(LCD_CTRL_PORT,RW);
	Delay_ms(1);
	SET_BIT(LCD_CTRL_PORT,E);
	Delay_ms(1);
	LCD_DATA_PORT = command;
	Delay_ms(1);
	CLEAR_BIT(LCD_CTRL_PORT,E);
	Delay_ms(1);
}


void LCD_displayCharacter(uint8_t data)
{
	    SET_BIT(LCD_CTRL_PORT,RS);
		CLEAR_BIT(LCD_CTRL_PORT,RW);
		Delay_ms(1);
		SET_BIT(LCD_CTRL_PORT,E);
		Delay_ms(1);
		LCD_DATA_PORT = data;
		Delay_ms(1);
		CLEAR_BIT(LCD_CTRL_PORT,E);
		Delay_ms(1);
}

void LCD_displayString(uint8_t *Str)
{

	uint8_t itr=0;
	while(Str[itr] != '\0')
	{
		LCD_displayCharacter(Str[itr]);
		itr++;
	}

}

void LCD_cursorPosition(uint8_t row, uint8_t col)
{
	uint8_t Address;

	switch(row)
	{

	case row1:
		          Address=col;
		          break;
	case row2:
		           Address=col+0x40;
		           break;
	}

	LCD_sendCommand(Address|SET_CURSOR_POSTION);

	}

void LCD_displayString_atPostion(uint8_t row, uint8_t col, uint8_t *Str)
{
	LCD_cursorPosition(row,col);
	LCD_displayString(Str);
}


void SYS(void)
{
	        NVIC_ST_CTRL_R    = INITIALIZE_TO_ZERO;
		NVIC_ST_RELOAD_R  = SYSTEM_CLK_SPEED_KHZ;
	        NVIC_ST_CURRENT_R = INITIALIZE_TO_ZERO;
	        NVIC_ST_CTRL_R    = SYSTICK_ENABLE;
}




void Delay_ms(uint32_t time)
{
	 int i;
	 for(i=0;i<time;++i)
	 {
		 SYS();
		 while(TIME_IS_RUNNING);
	 }
}









