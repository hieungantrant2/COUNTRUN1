/*
 * lcd.h
 *
 *  Created on: Apr 25, 2019
 *      Author: Tran Hieu Ngan
 */

#ifndef LCD_LIB_LCD_H_
#define LCD_LIB_LCD_H_
#include <msp430.h>

# define EN_ABLE BIT5
# define LCD_RS BIT4
# define line_1 0x80
# define line_2 0xC0

void write_coment(int coment);
void Lcd_Str_Cp(char *str);
void lcd_init(void);
void Lcd_Chr_Cp(char c);
void xung_lcd(void);
void lcd_config(void);



#endif /* LCD_LIB_LCD_H_ */
