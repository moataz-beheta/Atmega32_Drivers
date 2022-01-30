/*
 * PWM.c
 *
 * Created: 7/17/2021 5:10:42 PM
 * Author : Moataz
 */ 

#include <avr/io.h>


int main(void)
{
	/*		OC0 output			*/
	/*		Mode of Pwm = fast .. prescaller	*/
	DDRB=0xFF;
	TCCR0 = 0b01111001; 
	/*		Duty cycle*/
	OCR0 = 64;
    /* Replace with your application code */
    while (1) 
    {
    }
}

