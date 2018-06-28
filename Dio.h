/*
 * Dio.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: KAREEM
 */

#ifndef DIO_H_
#define DIO_H_
#include".\typedefs.h"
#define A (volatile u8 *)0x39
#define B (volatile u8 *)0x36
#define C (volatile u8 *)0x33
#define D (volatile u8 *)0x30
#define output 1
#define input  0
#define PORTA *(volatile u8 *)0x3B
#define PORTB *(volatile u8 *)0x38
#define PORTD (volatile u8 *)0x32

void port_write(u8 port,u8 value);
void port_direction(u8 port,u8 state);
u8 pin_read(u8 port,u8 pin);
void pin_write(u8 port,u8 pin,u8 value);
u8 port_read(void* port);
void pin_direction(u8 port,u8 pin,u8 state);


#endif /* DIO_H_ */
