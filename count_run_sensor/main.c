


#include <msp430.h> 
#include"adc.lib/adc.h"
/**
 * main.c
 */
int step_run(void);
int sensor; // sensor can be 265
void main(void)
{
    int number_step;
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	DCOCTL = CALDCO_1MHZ;
	BCSCTL1 = CALBC1_1MHZ;
	adc_init();//p1.1
while(1)
{
    number_step=step_run();
}

}
int step_run(void)
{
 int static k=-1,adc_before,adc;// pass the fist k alway increa 1
 adc_before=adc;
 adc=adc_tranfer();
 if((adc>(adc_before+sensor))||(adc<(adc_before-sensor)))
{
     k++;
}
 return k;
}
