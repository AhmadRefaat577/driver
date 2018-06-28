/*
 * I2C_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: KAREEM
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_
#include".\typedefs.h"
#define True 1
#define False 0

#define TWINT 7
#define TWEN 2
#define	TWSTA 5
#define TWSTO 4


#define START_TX 0x08
#define REPEATED_START 0x10
#define SLAVE_W_ACK 0x18
#define SLAVE_W_NO_ACK 0x20
#define DATA_TX_ACK 0x28
#define DATA_TX_NO_ACK 0x30
#define Arbitration lost in SLA+W or data 0x38
#define DATA_RX_ACK 0x50
#define SLAVE_R_ACK 0x40


void I2C_vInit(void);
void I2C_Send_Start(void);
void I2C_Send_U8data(u8 u8data);
void I2C_Send_Stop(void);
u8 I2C_Recieve_U8data(void);




#endif /* I2C_INTERFACE_H_ */
