/*
 * main.c
 */
#include "tm4c123gh6pm.h"
#include "stdbool.h"
#include "stdint.h"
#include "driver.h"
#include "APIS.h"

int main(void) {
	
	Driver_Initi();
	//LCD_displayCharacter('A');
	LCD_displayString_atPostion(1,3,"A");
	//LCD_cursorPosition(1,2);
	LCD_displayString("22");
while(1)
{



}

	//return 0;
}
