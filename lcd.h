/*
 * lcd.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: KAREEM
 */

#ifndef LCD_H_
#define LCD_H_
#include".\typedefs.h"
void Lcd_vidSendCommand( u8 u8CmdCpy);
void Lcd_vidInit(void);
void Lcd_vidWriteCharctr(u8 u8DataCpy);
void go_xy(u8 line,u8 col);
void Lcd_vidWriteString(u8* U8DataCpy);
#endif /* LCD_H_ */
