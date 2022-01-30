
#include "STD_TYPES.h"
#include "Dio_interface.h"
#include "LCD_interface.h"
#include <util/delay.h>
int main(void)
{
    //LCD_Init_4Bits();
    //DIO_voidSetPinValue(PORTD,PIN0,HIGH);
    ////LCD_GOTOXY(1,12);
    //LCD_WriteChar_4Bits('M');
    //LCD_WriteChar_4Bits('o');
    //LCD_WriteChar_4Bits('a');
    //LCD_WriteChar_4Bits('t');
    //LCD_WriteChar_4Bits('a');
    //LCD_WriteChar_4Bits('z');
    //LCD_GOTOXY_4Bits(0,10);
    //LCD_WriteSTring_4Bits("MOU");
    //LCD_GOTOXY_4Bits(1,0);
    //LCD_WriteSTring_4Bits("MOUSTAFA");
	
	LCD_Init_4Bits();
	LCD_WriteChar_4Bits('M');
	LCD_WriteChar_4Bits('o');
	LCD_WriteChar_4Bits('a');
	LCD_WriteSTring_4Bits("MOUSTAFA");
	_delay_ms(500);
	LCD_DeleteChar_4Bits();
	_delay_ms(500);
	LCD_WriteChar_4Bits('z');
	_delay_ms(500);
	LCD_Clear_4Bits();
	
	//LCD_Init_8Bits();
	//_delay_ms(500);
	//LCD_WriteChar_8Bits('M');
	//LCD_WriteChar_8Bits('o');
	//LCD_WriteChar_8Bits('a');
	//LCD_WriteSTring_8Bits("MOUSTAFA");
	//_delay_ms(500);
	//LCD_DeleteChar_8Bits();
	//_delay_ms(500);
	//LCD_WriteChar_8Bits('z');
	//_delay_ms(500);
	//LCD_Clear_8Bits();
	
/*LCD_WriteChar4('M');
LCD_WriteChar4('O');
LCD_WriteChar4('U');
LCD_WriteChar4('S');
LCD_WriteChar4('T');
LCD_WriteChar4('A');
LCD_WriteChar4('F');
LCD_WriteChar4('A');*/
   
    while (1) 
    {
    }
return 0;
}

