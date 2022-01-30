#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "EXTI_interface.h"
#include <util/delay.h>
#define F_CPU	16000000UL

void EXTI0_Func(void)
{
	DIO_voidSetPinValue(PORTC,PIN7,HIGH);
	_delay_ms(1000);
	DIO_voidSetPinValue(PORTC,PIN7,LOW);
	_delay_ms(1000);
}

int main ()
{
	EXTI0_voidSetCallBack(EXTI0_Func);
	/*	External interrupt 0 pin input and Internal Pull-Up	*/
	DIO_voidSetPinDirection(PORTD,PIN2,INPUT);
	DIO_voidSetPinValue(PORTD,PIN2,HIGH);
	/*	C7 Is output Pin For LED for EXTI0					*/
	DIO_voidSetPinDirection(PORTC,PIN7,OUTPUT);
	/*	C2 Is output Pin For LED							*/
	DIO_voidSetPinDirection(PORTC,PIN2,OUTPUT);
	
	EXTI0_voidEnable();
	GIE_voidEnable();
	while(1)
	{
			DIO_voidSetPinValue(PORTC,PIN2,HIGH);
			_delay_ms(1000);
			DIO_voidSetPinValue(PORTC,PIN2,LOW);
			_delay_ms(1000);
	}
	return 0 ;
}