#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Dio_interface.h"
#include "LCD_interface.h"
#include "SPI_interface.h"
#define F_CPU	16000000UL
#include <util/delay.h>


#define MOSI	PORTB, PIN5
#define MISO	PORTB, PIN6
#define SCK		PORTB, PIN7
#define SS		PORTB, PIN4

u8 data= '0';

int main(void)
{
SPI_Slave_init				();
SPI_Clock_Data_Setting		();

DIO_voidSetPinDirection(MOSI, INPUT);
DIO_voidSetPinDirection(MISO, OUTPUT);
DIO_voidSetPinDirection(SCK, INPUT);
DIO_voidSetPinDirection(SS, INPUT);

DIO_voidSetPinDirection(PORTC,	PIN0,	OUTPUT);
//LCD
	DIO_voidSetPinDirection(PORTC,	PIN4,	OUTPUT);
	DIO_voidSetPinDirection(PORTC,	PIN5,	OUTPUT);
	DIO_voidSetPinDirection(PORTC,	PIN6,	OUTPUT);
	DIO_voidSetPortDirection(PORTD,	0xFF);

LCD_init();
//LCD_WriteChar4(data);
	while (1) 
    {
		//_delay_ms(2000);
		//LCD_WriteString("Not Sent");
		DIO_voidSetPinValue(PORTC,	PIN0,	LOW);
		
		data=SPI_Receive();
		
		LCD_WriteChar4(data);
		
		//if (data == 'A' )
		//{
		//	DIO_voidSetPinValue(PORTC,	PIN0,	HIGH);
		//	_delay_ms(1000);
		//	DIO_voidSetPinValue(PORTC,	PIN0,	LOW);
		//	_delay_ms(1000);
		//}
		//else
		//{
		//	DIO_voidSetPinValue(PORTC,	PIN0,	LOW);
		//	_delay_ms(1000);
		//}

    }
}