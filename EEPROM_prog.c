/*
 * EEPROM_prog.c
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
#include".\EEPROM.h"
u8 returnv=0;
void EEPROM_vInit(void)
{
	I2C_vInit();
}
u8 EEPROM_u8Write_Byte(u16 u16location,u8 u8data)
{
	I2C_Send_Start();
	if(I2C_Check_Status(START_TX)==True)
	{
		I2C_Send_U8data((EEPROM_ADDRESS_W)|((u16location&0b11000000)>>7));
		if(I2C_Check_Status(SLAVE_W_ACK)==True)
		{
			I2C_Send_U8data((u8)u16location);
			if(I2C_Check_Status(DATA_TX_ACK)==True)
			{
				I2C_Send_U8data(u8data);
				if(I2C_Check_Status(DATA_TX_ACK)==True)
				{
					I2C_Send_Stop();
					return returnv=True;
				}
				else
				{
					//Do Nothing
				}
			}
			else
			{
				//Do Nothing
			}
		}
		else
		{
			//Do Nothing
		}
	}
	else
	{
		//Do Nothing
	}

	return False;

}
u8 EEPROM_u8Read_Byte(u16 u16location,u8* u8data)
{
	I2C_Send_Start();
	if(I2C_Check_Status(START_TX)==True)
	{

		I2C_Send_U8data((EEPROM_ADDRESS_W)|((u16location&0b11000000)>>7));
		if(I2C_Check_Status(SLAVE_W_ACK)==True)
		{
			I2C_Send_U8data((u8)u16location);
			if(I2C_Check_Status(DATA_TX_ACK)==True)
			{
				I2C_Send_Start();
				if(I2C_Check_Status(REPEATED_START)==True)
				{
					I2C_Send_U8data((EEPROM_ADDRESS_R)|((u16location&0b11000000)>>7));
					if(I2C_Check_Status(SLAVE_R_ACK)==True)
					{
						*u8data=I2C_Recieve_U8data();
						I2C_Send_Stop();
						return True;

				}
					else
									{
										//Do Nothing
									}
								}
								else
								{
									//Do Nothing
								}
							}
							else
							{
								//Do Nothing
							}
						}
						else
						{
							//Do Nothing
						}


	}
	return False;
}



