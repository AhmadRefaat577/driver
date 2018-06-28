/*
 * UART_prog.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: KAREEM
 */
#include<stdlib.h>
#include".\UARTconfig.h"
#include".\UART_interface.h"
#include".\typedefs.h"
#include".\lib.h"
#include".\lcdmacros.h"
#include<util/delay.h>
#include".\Dio.h"
#include".\lcd.h"
#include<avr/io.h>
#include<avr/interrupt.h>
void UART_voidInit(void)
{
	SET_BIN(UCSRB,3);//tx enable
	SET_BIN(UCSRB,4);//rx enable
	//to access ubrr RESET_BIN(UCSRB,15);
	UBRRH=((u8)ubrr>>8);
	UBRRL=((u8)ubrr);
	//UBRRL = 51;




}
void UART_voidSendbyte(u8 u8byte)
{
	while(GETBIT(UCSRA,5)==0);//UDRE is empty
	UDR=u8byte;
}
u8 UART_u8Recievebyte(void)
{
	while(GETBIT(UCSRA,7)==0);//RECEIVE COMPLETE
	return UDR;
}


