/*
 * APIS.h
 *
 *  Created on: Apr 20, 2019
 *      Author: ahmed
 */

/*
 *File description: this file includes all prototypes for the driver
 */

#ifndef APIS_H_
#define APIS_H_
#include"stdint.h"


/*
 * pre: you have to choose your target and connect it to the device.
 * post:your systick timer is initialized and ready to be used.
 */
void SYS(void);

/*
 * pre:your systick timer is initialized.
 * post:the delay is set by your desired value.
 */

void Delay_ms(uint32_t time);

/*
 * pre:the driver is connected to the target.
 * post:the command is set.
 */
void LCD_sendCommand(uint8_t command);

void Driver_Initi(void);

void LCD_displayCharacter(uint8_t data);
void LCD_displayString(uint8_t *Str);
void LCD_cursorPosition(uint8_t row, uint8_t col);
void LCD_displayString_atPostion(uint8_t row, uint8_t col, uint8_t *Str);




#endif /* APIS_H_ */
