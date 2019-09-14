/*
 * driver.h
 *
 *  Created on: Apr 18, 2019
 *      Author: ahmed
 */

/*
 * File description: this file includes all macros used in the driver.
 *
 */

#include"tm4c123gh6pm.h"
#include"stdbool.h"

#ifndef DRIVER_H_
#define DRIVER_H_

/*
 * Common used macros.
 */
#define SET_BIT(REG,BIT)      (REG|=BIT)
#define CLEAR_BIT(REG,BIT)    (REG&=(~BIT))
#define INITIALIZE_TO_ZERO     0

/*
 * Systick timer macros
 */
#define SYSTEM_CLK_SPEED_KHZ (16000-1)
#define SYSTICK_ENABLE       5
#define TIME_IS_RUNNING      (bool)((NVIC_ST_CTRL_R&0x10000)==0)

/*
 * GPIO macros
 */

#define GPIO_CLK_CTRL_R   (SYSCTL_RCGCGPIO_R)
#define CLK_ENABL         (0x03)
#define  RS               (1<<5)
#define  RW               (1<<6)
#define  E                (1<<7)

#define LCD_CTRL_PORT     (GPIO_PORTA_DATA_R)
#define LCD_CTRL_DIR_R    (GPIO_PORTA_DIR_R)
#define LCD_CTRL_DEN_R    (GPIO_PORTA_DEN_R)

#define LCD_DATA_PORT     (GPIO_PORTB_DATA_R)
#define LCD_DATA_DIR_R    (GPIO_PORTB_DIR_R)
#define LCD_DATA_DEN_R    (GPIO_PORTB_DEN_R)
#define DATA_ENABLE       (0xFF)
/*
 * LCD commands
 *
 */
#define row1                             (0)
#define row2                             (1)
#define CLEAR_SCREEN                     (0x01)
#define RETURN_CURSOR_HOME               (0x02)
#define INCREMENT_CURSOR                 (0x06)
#define CURSOR_BLINKING                  (0x0F)
#define TWO_LINES_LCD_Eight_BIT_MODE     (0x38)
#define TWO_LINES_LCD_FOUR_BIT_MODE      (0x28)
#define SET_CURSOR_POSTION               (0x80)



#endif /* DRIVER_H_ */
