/*
 * EEPROM.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: KAREEM
 */

#ifndef EEPROM_H_
#define EEPROM_H_
#include".\typedefs.h"
#define EEPROM_ADDRESS_W		0xA0
#define EEPROM_ADDRESS_R		0xA1

void EEPROM_vInit(void);

u8 EEPROM_u8Write_Byte(u16 Location,u8 u8Byte);

u8 EEPROM_u8Read_Byte(u16 Location,u8* Recieved_Data);


#endif /* EEPROM_H_ */
