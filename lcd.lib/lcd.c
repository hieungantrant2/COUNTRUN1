/*
 * lcd.c
 *
 *  Created on: Apr 25, 2019
 *      Author: Tran Hieu Ngan
 */
#include <lcd.lib/lcd.h>
#include <msp430.h>

#include <string.h>
void lcd_init(void)
{
    WDTCTL = WDTPW | WDTHOLD;
    P1SEL &= ~(BIT4 +BIT5);
    P1SEL2 &= ~(BIT4 +BIT5);
    P1DIR |= (BIT4 +BIT5);
    P2SEL = 0;
    P2SEL2 =0;
    P2DIR =0xFF;
}

void write_coment(int coment)
{
    P2OUT = coment;
    P1OUT &= ~LCD_RS;
    xung_lcd();

}
void Lcd_Str_Cp(char *str) //
{
unsigned char i = 0;
while(str[i]!=0) //
{                   //
Lcd_Chr_Cp(str[i]);
i++;
}
}
void Lcd_Chr_Cp(char c) //
{

P2OUT = c;
P1OUT |= LCD_RS;
P1OUT |= EN_ABLE;
xung_lcd();
//P2OUT = 0;
}
void xung_lcd(void)
{
    P1OUT |= EN_ABLE;
    _delay_cycles(330);
    P1OUT &= ~EN_ABLE;
    _delay_cycles(330);
}
void lcd_config(void)
{
    lcd_init();
    write_coment(0x38);
    write_coment(0x0E);
    write_coment(0x06);
    // write_coment(0x0C);
    write_coment(0x01);

}


