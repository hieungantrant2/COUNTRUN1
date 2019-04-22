#include <msp430.h> 
int i;

/**
 * main.c
 */
void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	DCOCTL = CALDCO_1MHZ;
	BCSCTL1 = CALBC1_1MHZ;
	P1SEL &= ~(BIT3+BIT6);
	P1SEL2 &= ~(BIT3+BIT6);
	P1DIR |=BIT6;
	P1DIR &= ~BIT3;
	P1REN |= BIT3;
	P1OUT |= BIT3;// p1.3 pull up resistor
	P1IE  |= BIT3;
	P1IES |= BIT3;  // interrupt pending when p1.3 from 1->0
	_bis_SR_register(GIE);
	while(1)
	{


	}
}
#pragma vector = PORT1_VECTOR;
__interrupt void juminone (void)
{
    if (P1IFG&BIT3)
    {
        P1OUT |= BIT6;
        _delay_cycles(500000);
        P1OUT &= ~BIT6;
        i++;
        P1IFG&=~ BIT3;
    }
}

