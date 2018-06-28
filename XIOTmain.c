/*
 * XIOTmain.c
 *	 
 *      Author: KAREEM
	in this project i used :
	-AVR atmega32 Microcontroller.
	-SWITCH,LED.
	-Serial communication protocol " UART" for sending state of LED and state of SWITCH.
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
	DDRA=0xff;//PORT A is output
	DDRB=0x00;//PORT B is INPUT and Pull up.
	PORTB=0xff;
	TIMER_vidInit();// intiate timer driver 
	UART_voidInit();// itiate UART driver 
		while(1)
	{

		if(pin_read(B,4)==0) //check if switch pressed or not
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


	ISR(TIMER0_OVF_vect)
{	int ms_var=0;
	OVF_counter ++;
	if(OVF_counter==32)  //some calculations to make timer comes after 3 sec to get temperature reading and send it through UART
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

