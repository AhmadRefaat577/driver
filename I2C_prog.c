/*
 * I2C_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: KAREEM
 */
#include<stdlib.h>
#include".\typedefs.h"
#include".\lib.h"
#include".\lcdmacros.h"
#include<util/delay.h>
#include".\Dio.h"
#include".\lcd.h"
#include<avr/io.h>
#include<avr/interrupt.h>
#include".\I2C_interface.h"
void I2C_vInit(void)
{
	TWCR=(1<<TWEN);
	TWBR=2;
	TWSR=0;
	TWAR=0x02;


}
void I2C_Send_Start(void)
{
	TWCR=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while(!(TWCR&(1<<TWINT)));

}
void I2C_Send_U8data(u8 u8data)
{	TWDR=u8data;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(!(TWCR&(1<<TWINT)));

}
void I2C_Send_Stop(void)
{
	TWCR = (1<<TWINT) | (1<<TWSTO) | (1<<TWEN);
}
u8 I2C_Recieve_U8data(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN);
	while(!(TWCR&(1<<TWINT)));
	return TWDR;
}
u8 I2C_Check_Status(u8 u8status)
{u8 ReturnValue=0;
	if((TWSR & 0xf8) ==u8status)
		ReturnValue=True;
	else if((TWSR & 0xf8) !=u8status)
		ReturnValue=False;
return ReturnValue;
}
