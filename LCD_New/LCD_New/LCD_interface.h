#ifndef			LCD_INTERFACE_H
#define			LCD_INTERFACE_H

/*		8-Bits Mode		*/
void	LCD_Init_8Bits(void);
void	LCD_SendCMD_8Bits(u8 CMD);
void	LCD_WriteChar_8Bits(u8 Data);
void	LCD_GOTOXY_8Bits(u8 LINE_NUM,u8 POSITION);
void	LCD_WriteSTring_8Bits(u8 * ptr);
void	LCD_DeleteChar_8Bits(void);
void	LCD_Clear_8Bits(void);

/*		4-Bits Mode		*/
void	LCD_Init_4Bits(void);
void    LCD_SendCMD_4Bits(u8 cmd);
void    LCD_WriteChar_4Bits(u8 Data);
void    LCD_GOTOXY_4Bits(u8 LINE_NUM,u8 POSITION);
void    LCD_WriteSTring_4Bits(u8 * ptr);
void	LCD_DeleteChar_4Bits(void);
void	LCD_Clear_4Bits(void);

#endif