/*
 * lcd.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: KAREEM
 */
#include".\lcdmacros.h"
#include".\lcd.h"
#include".\Dio.h"
#include<util/delay.h>
#define data A
#define command
void Lcd_vidSendCommand(u8 U8CmdCpy)
{

	pin_write(D,0,0);
	pin_write(D,7,1);

	port_write(data,U8CmdCpy);
	pin_write(D,7,0);
	_delay_us(5000);
	pin_write(D,7,1);

}
void Lcd_vidInit(void)
{
	Lcd_vidSendCommand(Clear_Display);
	Lcd_vidSendCommand(Return_Home);
	Lcd_vidSendCommand(Entry_Mode_Set);
	Lcd_vidSendCommand(Display_ON_OFF_Control);
	Lcd_vidSendCommand(Function_Set);

}
void Lcd_vidWriteCharctr(u8 U8DataCpy)
{

		pin_write(D,0,1);
		pin_write(D,7,1);
		port_write(data,U8DataCpy);
		pin_write(D,7,0);
		_delay_us(5000);
		pin_write(D,7,1);
		_delay_us(10000);
}
void go_xy(u8 line,u8 col)
{

	if (line==1)
	{
		Lcd_vidSendCommand(col|0b10000000);
	}
	if (line==2)
	{
		Lcd_vidSendCommand((col+(0x40))|0b10000000);
	}
}

void Lcd_vidWriteString(u8* U8DataCpy)

{u8 counter=0;
	while(U8DataCpy[counter]!=0)
	{
	Lcd_vidWriteCharctr(U8DataCpy[counter]);
	_delay_ms(5) ;
	counter++;

	}
}
