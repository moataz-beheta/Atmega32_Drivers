#ifndef		LCD_CONFIG_H
#define		LCD_CONFIG_H

#define		CONTROL_PORT    PORTC
#define		LCD_RS			PIN4
#define		LCD_RW			PIN5
#define		LCD_EN			PIN6

#define		DATA_PORT		PORTD

#define		Cursor				ON				//ON or OFF
#define		Cursor_Blink		OFF				//ON or OFF
#define		Display				ON				//ON or OFF (Display Status)

#define		Num_Lines			2		 		//1 or 2 Lines
#define		Font	 			_5x11			//_5x8 or _5x11 dots
#define		I_D		 			Increases		//Increases "English" or Decreases "Arabic"
#define		SH		 			OFF				//ON or OFF (Shift of Entire Display)

#define		Shift_Pattern		Left			//Left, Shift cursor to left, AC is decreased by 1
												//Right, Shift cursor to Right, AC is increased by 1
												//All_Left, Shift all display to the left, cursor moves according to the display
												//All_Right, Shift all display to the Right, cursor moves according to the display


#endif