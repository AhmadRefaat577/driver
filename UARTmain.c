/*
 * XIOTmain.c
 *
 *  
 *      Author: Ahmed
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
#include "TIMER_interface.h"
#include "TIMER_private.h"
#include<avr/interrupt.h>
char temperaturereading=0;
int OVF_counter=0;
void main(void)
{
	DDRA=0xff;
	DDRB=0x00;
	PORTB=0xff;
	TIMER_vidInit();
	UART_voidInit();
		while(1)
	{

		if(pin_read(B,4)==0)
		{
			pin_write(A,4,1);
			UART_voidSendbyte('O');
			UART_voidSendbyte('N');
			UART_voidSendbyte('p');
			UART_voidSendbyte('r');
			UART_voidSendbyte('e');
			UART_voidSendbyte('s');
			UART_voidSendbyte('s');
			UART_voidSendbyte('e');
			UART_voidSendbyte('d');
		}
		else if(GETBIT(PORTB,4)==1)
		{
			PORTA=0x00;
			UART_voidSendbyte('O');
			UART_voidSendbyte('F');
			UART_voidSendbyte('F');
		}
	}

}

/*u8 readed_value=0;
		readed_value=UART_u8Recievebyte();
		if(readed_value==0x01)
		{
			PORTB=0b10000001;
		}
		else if(readed_value==0x05)
		{
			PORTB=0b00000000;
		}

	}
}
void fun1(void){
	static int x=5 ;
	x++;
}
void fun2(void)
{
	static int x=4;
	x--;
}
 */

	ISR(TIMER0_OVF_vect)
{	int ms_var=0;
	OVF_counter ++;
	if(OVF_counter==32)
	{
		OVF_counter=0;
		TCNT0=192;
		ms_var++;
		if(ms_var==3)
		{
			ms_var=0;
			UART_voidSendbyte(temperaturereading);

		}
	}
}

