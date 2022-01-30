
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Dio_interface.h"
#include "SPI_interface.h"
#define F_CPU	16000000UL
#include <util/delay.h>

#define MOSI	PORTB, PIN5
#define MISO	PORTB, PIN6
#define SCK		PORTB, PIN7
#define SS		PORTB, PIN4
 

int main(void)
{
SPI_Master_init				();
SPI_Clock_Data_Setting		();

DIO_voidSetPinDirection(MOSI, OUTPUT);
DIO_voidSetPinDirection(MISO, INPUT);
DIO_voidSetPinDirection(SCK, OUTPUT);
DIO_voidSetPinDirection(SS, INPUT);
DIO_voidSetPinValue (SS, HIGH); // Pull-Up for SS pin
DIO_voidSetPinDirection(PORTB,PIN3,OUTPUT);
DIO_voidSetPinValue (PORTB,PIN3, LOW);
DIO_voidSetPinDirection(PORTC,PIN0,OUTPUT);

	while (1) 
    {
	DIO_voidSetPinValue(PORTC,PIN0,LOW);
	_delay_ms(500);
	SPI_Transmit('A');
	//_delay_ms(1000);
	DIO_voidSetPinValue(PORTC,PIN0,HIGH);
	_delay_ms(200);			
    }
}