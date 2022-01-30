#include	"STD_types.h"
#include	"Dio_interface.h"
#include	<util/delay.h>

int main(void)
{
	//DIO_voidSetPinDirection(PORTC , PIN7 , OUTPUT);
	DIO_voidSetPortDirection(PORTA	,	OUTPUT);
	DIO_voidSetPinDirection(PORTB , PIN1 , OUTPUT);
	
	
	
	while(1)
	{
				/*		LED TOGGLE		*/
		/*
		DIO_voidSetPinValue(PORTC , PIN7 , HIGH);
		_delay_ms(1000);
		
		DIO_voidSetPinValue(PORTC , PIN7 , LOW);
		_delay_ms(1000);
		*/

		/*		LED With push button		*/
		/*
		if (DIO_u8GetPinValue(PORTB , PIN0)==1)
		{
			DIO_voidSetPinValue(PORTC , PIN7 , HIGH);
		}
		
		else
		{
			DIO_voidSetPinValue(PORTC , PIN7 , LOW);			
		}
		*/

		
		/*		7-SEGMENTs			*/
		DIO_voidSetPinValue(PORTB , PIN1 , HIGH);
		/*DIO_voidSetPinValue(PORTA , PIN0 , HIGH);
		DIO_voidSetPinValue(PORTA , PIN1 , HIGH);
		DIO_voidSetPinValue(PORTA , PIN2 , HIGH);
		DIO_voidSetPinValue(PORTA , PIN3 , HIGH);
		DIO_voidSetPinValue(PORTA , PIN4 , HIGH);
		DIO_voidSetPinValue(PORTA , PIN5 , HIGH);*/
		
		DIO_voidSetPortValue(PORTA , 0xf0);
	}
	
	return 0 ;
}