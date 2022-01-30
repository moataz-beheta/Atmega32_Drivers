/*
 * ADC.c
 *
 * Created: 9/23/2021 3:02:43 PM
 * Author : Moataz
 */ 

#include "STD_TYPES.h"
#include "Dio_interface.h"
#include "ADC_interface.h"
//#include <util/delay.h>


int main(void)
{
	ADC_Init		();
		
	u16	Local_Digital_Value=0;
	u16	Local_Analog_Value=0;
	
	DIO_voidSetPinDirection(PORTC,PIN2,OUTPUT);	//led0
	DIO_voidSetPinDirection(PORTC,PIN7,OUTPUT);	//led1
	DIO_voidSetPinDirection(PORTD,PIN3,OUTPUT);	//led2
	
	DIO_voidSetPinValue(PORTC,PIN2,LOW);
	DIO_voidSetPinValue(PORTC,PIN7,LOW);
	DIO_voidSetPinValue(PORTD,PIN3,LOW);
	
    /* Replace with your application code */
    while (1) 
    {
		Local_Digital_Value = ADC_Read		(7);
		Local_Analog_Value = (Local_Digital_Value*5000UL)/1024;
		
		if (Local_Analog_Value <=1000)
		{
			DIO_voidSetPinValue(PORTC,PIN2,HIGH);	//led0
			DIO_voidSetPinValue(PORTC,PIN7,LOW);	//led1
			DIO_voidSetPinValue(PORTD,PIN3,LOW);	//led2
		}
		
		else if (Local_Analog_Value <=4000 && Local_Analog_Value >1000 )
		{
			DIO_voidSetPinValue(PORTC,PIN2,LOW);	//led0
			DIO_voidSetPinValue(PORTC,PIN7,HIGH);	//led1
			DIO_voidSetPinValue(PORTD,PIN3,HIGH);	//led2
		}

		else
		{
			DIO_voidSetPinValue(PORTC,PIN2,HIGH);	//led0
			DIO_voidSetPinValue(PORTC,PIN7,LOW);	//led1
			DIO_voidSetPinValue(PORTD,PIN3,HIGH);	//led2
		}
		 
    }
}

