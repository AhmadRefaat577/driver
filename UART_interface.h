/*
 * UART_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: KAREEM
 */

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_
#include".\UARTconfig.h"
#include".\typedefs.h"
#define	 ubrr (((fosc*1000000)/(16.0*baudrate))-1)
void UART_voidInit(void);
void UART_voidSendbyte(u8 u8byte);
u8 UART_u8Recievebyte(void);
#endif /* UART_INTERFACE_H_ */
