#include		"STD_TYPES.h"
#include		"DIO_interface.h"
#include 		"LCD_interface.h"
#include 		"LCD_private.h"
#include 		"LCD_configuration.h"
#include		<util/delay.h>

void LCD_Init_8Bits(void)
{
	DIO_voidSetPortDirection(DATA_PORT,0xFF);
	DIO_voidSetPinDirection(CONTROL_PORT,LCD_RS,OUTPUT);
	DIO_voidSetPinDirection(CONTROL_PORT,LCD_RW,OUTPUT);
	DIO_voidSetPinDirection(CONTROL_PORT,LCD_EN,OUTPUT);
	
	u8	Function_Set	=	0b00100000	;
	u8	Display_Set		= 	0b00001000	;
	u8	Entry_Mode		= 	0b00000100	;
	
	
	///////// Function Set /////////
	/*	Set Font							*/
	#if		Font == _5x8
	Function_Set&=~ (1<<2);
	#elif	Font == _5x11
	Function_Set |= 1<<2;
	#else
	#error	"Wrong Choice of LCD Font!"
	#endif

	/*	Set Number of Lines					*/
	#if		Num_Lines == 1
	Function_Set&=~(1<<3);
	#elif	Num_Lines == 2
	Function_Set|= 1<<3;
	#else
	#error	"Wrong Choice of LCD Number of Lines!"
	#endif
	
	/*	Choose 8-bits mode					*/
	Function_Set|= 1<<4;

	
	///////// Display /////////
	/*	Choose Display ON/OFF Status		*/
	#if		Display == OFF
	Display_Set&=~(1<<2);
	#elif	Display == ON
	Display_Set|= 1<<2;
	#else
	#error	"Wrong Choice of LCD Display ON/OFF Status!"
	#endif

	/*	Choose Cursor ON/OFF Status		*/
	#if		Cursor == OFF
	Display_Set&=~(1<<1);
	#elif	Cursor == ON
	Display_Set|= 1<<1;
	#else
	#error	"Wrong Choice of LCD Cursor ON/OFF Status!"
	#endif

	/*	Choose Cursor blinking ON/OFF Status		*/
	#if		Cursor_Blink == OFF
	Display_Set&=~(1<<0);
	#elif	Cursor_Blink == ON
	Display_Set|= 1<<0;
	#else
	#error	"Wrong Choice of LCD Cursor blinking ON/OFF Status!"
	#endif
	
	
	///////// Entry Mode /////////
	/*	Choose Move Direction				*/
	#if		I_D == Decreases
	Entry_Mode&=~(1<<1);
	#elif	I_D == Increases
	Entry_Mode|= 1<<1;
	#else
	#error	"Wrong Choice of LCD Move Direction!"
	#endif

	/*	Choose Shift of Entire Display				*/
	#if		SH == OFF
	Entry_Mode&=~(1<<0);
	#elif	SH == ON
	Entry_Mode|= 1<<0;
	#else
	#error	"Wrong Choice of LCD Shift of Entire Display!"
	#endif

	_delay_ms(35);
	LCD_SendCMD_8Bits(Function_Set);

	_delay_ms(1);
	LCD_SendCMD_8Bits(Display_Set);

	_delay_ms(1);
	LCD_SendCMD_8Bits(0x01); //clear LCD

	_delay_ms(2);
	LCD_SendCMD_8Bits(Entry_Mode);
}

void LCD_Init_4Bits(void)
{
	DIO_voidSetPinDirection(DATA_PORT,PIN4,OUTPUT);
	DIO_voidSetPinDirection(DATA_PORT,PIN5,OUTPUT);
	DIO_voidSetPinDirection(DATA_PORT,PIN6,OUTPUT);
	DIO_voidSetPinDirection(DATA_PORT,PIN7,OUTPUT);
	
	DIO_voidSetPinDirection(CONTROL_PORT,LCD_RS,OUTPUT);
	DIO_voidSetPinDirection(CONTROL_PORT,LCD_RW,OUTPUT);
	DIO_voidSetPinDirection(CONTROL_PORT,LCD_EN,OUTPUT);
	
	u8	Function_Set	=	0b00000000	;
	u8	Display_Set		= 	0b10000000	;
	u8	Entry_Mode		= 	0b01000000	;
	
	
	///////// Function Set /////////
	/*	Set Font							*/
	#if		Font == _5x8
	Function_Set&=~ (1<<6);
	#elif	Font == _5x11
	Function_Set |= 1<<6;
	#else
	#error	"Wrong Choice of LCD Font!"
	#endif

	/*	Set Number of Lines					*/
	#if		Num_Lines == 1
	Function_Set&=~(1<<7);
	#elif	Num_Lines == 2
	Function_Set|= 1<<7;
	#else
	#error	"Wrong Choice of LCD Number of Lines!"
	#endif
	
	/*	Choose 4-bits mode					*/
	Function_Set&=~(1<<4);
	
	///////// Display /////////
	/*	Choose Display ON/OFF Status		*/
	#if		Display == OFF
	Display_Set&=~(1<<6);
	#elif	Display == ON
	Display_Set|= 1<<6;
	#else
	#error	"Wrong Choice of LCD Display ON/OFF Status!"
	#endif

	/*	Choose Cursor ON/OFF Status		*/
	#if		Cursor == OFF
	Display_Set&=~(1<<5);
	#elif	Cursor == ON
	Display_Set|= 1<<5;
	#else
	#error	"Wrong Choice of LCD Cursor ON/OFF Status!"
	#endif

	/*	Choose Cursor blinking ON/OFF Status		*/
	#if		Cursor_Blink == OFF
	Display_Set&=~(1<<4);
	#elif	Cursor_Blink == ON
	Display_Set|= 1<<4;
	#else
	#error	"Wrong Choice of LCD Cursor blinking ON/OFF Status!"
	#endif
	
	
	///////// Entry Mode /////////
	/*	Choose Move Direction				*/
	#if		I_D == Decreases
	Entry_Mode&=~(1<<5);
	#elif	I_D == Increases
	Entry_Mode|= 1<<5;
	#else
	#error	"Wrong Choice of LCD Move Direction!"
	#endif

	/*	Choose Shift of Entire Display				*/
	#if		SH == OFF
	Entry_Mode&=~(1<<4);
	#elif	SH == ON
	Entry_Mode|= 1<<4;
	#else
	#error	"Wrong Choice of LCD Shift of Entire Display!"
	#endif


	_delay_ms(35);
	LCD_SendCMD_8Bits(0x22);
	LCD_SendCMD_8Bits(0x22);
	LCD_SendCMD_8Bits(Function_Set);

	_delay_ms(1);
	LCD_SendCMD_4Bits(0x00);
	LCD_SendCMD_4Bits(Display_Set);

	_delay_ms(1);
	LCD_SendCMD_4Bits(0x00);
	LCD_SendCMD_4Bits(0x10); //clear LCD

	_delay_ms(2);
	LCD_SendCMD_4Bits(0x00);
	LCD_SendCMD_4Bits(Entry_Mode);
}

void	LCD_WriteChar_8Bits(u8 Data)
{
	DIO_voidSetPinValue(CONTROL_PORT,LCD_RS,HIGH);
	DIO_voidSetPinValue(CONTROL_PORT,LCD_RW,LOW);
	DIO_voidSetPinValue(CONTROL_PORT,LCD_EN,HIGH);
	_delay_ms(5);
	DIO_voidSetPortValue(DATA_PORT,Data);
	DIO_voidSetPinValue(CONTROL_PORT,LCD_EN,LOW);
	_delay_ms(5);
	
}

void	LCD_SendCMD_8Bits(u8 CMD)
{
	DIO_voidSetPinValue(CONTROL_PORT,LCD_RS,LOW);
	DIO_voidSetPinValue(CONTROL_PORT,LCD_RW,LOW);
	DIO_voidSetPinValue(CONTROL_PORT,LCD_EN,HIGH);
	_delay_ms(5);
	DIO_voidSetPortValue(DATA_PORT,CMD);
	DIO_voidSetPinValue(CONTROL_PORT,LCD_EN,LOW);
	_delay_ms(5);
	
}

void LCD_SendCMD_4Bits(u8 cmd)
{
	DIO_voidSetPinValue(CONTROL_PORT,LCD_RS,LOW);
	DIO_voidSetPinValue(CONTROL_PORT,LCD_RW,LOW);
	DIO_voidSetPinValue(CONTROL_PORT,LCD_EN,HIGH);
	_delay_ms(5);
	

	u8 Dummy = (cmd & 0xf0) | (DATA_PORT & 0x0f);
	DIO_voidSetPortValue(DATA_PORT,Dummy);
	DIO_voidSetPinValue(CONTROL_PORT,LCD_EN,LOW);
	_delay_ms(5);
	
	DIO_voidSetPinValue(CONTROL_PORT,LCD_EN,HIGH);
	_delay_ms(5);
}

void LCD_WriteChar_4Bits(u8 Data)
{
	

	DIO_voidSetPinValue(CONTROL_PORT,LCD_RS,HIGH);
	DIO_voidSetPinValue(CONTROL_PORT,LCD_RW,LOW);
	DIO_voidSetPinValue(CONTROL_PORT,LCD_EN,HIGH);
	_delay_ms(5);


	u8 Dummy = (Data & 0xf0) | (DATA_PORT & 0x0f);
	DIO_voidSetPortValue(DATA_PORT,Dummy);
	DIO_voidSetPinValue(CONTROL_PORT,LCD_EN,LOW);
	_delay_ms(5);


	DIO_voidSetPinValue(CONTROL_PORT,LCD_EN,HIGH);
	Dummy = (Data << 4) | (DATA_PORT & 0x0f);
	DIO_voidSetPortValue(DATA_PORT,Dummy);
	_delay_ms(5);
	DIO_voidSetPinValue(CONTROL_PORT,LCD_EN,LOW);
	_delay_ms(5);
}

void LCD_GOTOXY_8Bits(u8 LINE_NUM,u8 POSITION)
{
	
	if((LINE_NUM ==0) && (POSITION<16))
	{
		LCD_SendCMD_8Bits((0x80 + POSITION));
	}
	else if ((LINE_NUM ==1) && (POSITION<16))
	{
		
		LCD_SendCMD_8Bits((0xC0 + POSITION));
	}
}

void LCD_GOTOXY_4Bits(u8 LINE_NUM,u8 POSITION)
{
	
	if((LINE_NUM ==0) && (POSITION<16))
	{
		int Local_Position=(0x80 + POSITION);
		LCD_SendCMD_4Bits(Local_Position);
		LCD_SendCMD_4Bits(Local_Position<<4);
	}
	else if ((LINE_NUM ==1) && (POSITION<16))
	{
		int Local_Position=(0xC0 + POSITION);
		LCD_SendCMD_4Bits(Local_Position);
		LCD_SendCMD_4Bits(Local_Position<<4);
	}
}

void LCD_WriteSTring_8Bits(u8 * ptr)
{
	u8 i = 0 ;
	
	while(ptr[i] != '\0')
	{
		LCD_WriteChar_8Bits(ptr[i]);
		i++;
	}

}

void LCD_WriteSTring_4Bits(u8 * ptr)
{
	u8 i = 0 ;
	
	while(ptr[i] != '\0')
	{
		LCD_WriteChar_4Bits(ptr[i]);
		i++;
	}

}

void LCD_DeleteChar_8Bits(void)
{
	LCD_SendCMD_8Bits(0x10);
	LCD_WriteChar_8Bits(' ');
	//_delay_ms(10);
	LCD_SendCMD_8Bits(0x10);
}

void LCD_DeleteChar_4Bits(void)
{
	LCD_SendCMD_4Bits(0x10);
	LCD_SendCMD_4Bits(0x10<<4);
	LCD_WriteChar_4Bits(' ');
	//_delay_ms(10);
	LCD_SendCMD_4Bits(0x10);
	LCD_SendCMD_4Bits(0x10<<4);
}

void LCD_Clear_8Bits(void)
{
	LCD_SendCMD_8Bits (0x01);		/* Clear display */
	_delay_ms(2);
	LCD_SendCMD_8Bits (0x80);		/* Cursor at home position */
}

void LCD_Clear_4Bits(void)
{
	LCD_SendCMD_4Bits (0x01);		/* Clear display */
	LCD_SendCMD_4Bits (0x01<<4);	/* Clear display */
	_delay_ms(2);
	LCD_SendCMD_4Bits (0x80);		/* Cursor at home position */
	LCD_SendCMD_4Bits (0x80<<4);	/* Cursor at home position */
}
//		// not init
//		u8	Cursor_Shift 	= 	0b00010000	;
//		/*	Choose Shift Pattern					*/
//		#if			Shift_Pattern == Left
//			Cursor_Shift&=~(1<<2);	// R/L
//			Cursor_Shift&=~(1<<3);	// S/C
//		#elif		Shift_Pattern == Right
//			Cursor_Shift|= (1<<2);  // R/L
//			Cursor_Shift&=~(1<<3);  // S/C
//		#elif		Shift_Pattern == All_Left
//			Cursor_Shift&=~(1<<2);	// R/L
//			Cursor_Shift|=(1<<3);  	// S/C
//		#elif		Shift_Pattern == All_Right
//			Cursor_Shift|=(1<<2);	// R/L
//			Cursor_Shift|=(1<<3);  	// S/C
//		#else
//		#error	"Wrong Choice of LCD Shift Pattern!"
//		#endif