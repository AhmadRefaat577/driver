/*
 * Dio.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: KAREEM
 */
#include".\typedefs.h"
#include".\lib.h"
#include".\Dio.h"
void port_direction(u8 port,u8 state)
{
	if (state==output)
	{
	*((volatile u8 *)( port+1))=0xff;
}
	else if (state==input)
	{
		*((volatile u8 *)( port+1))=0x00;
	}
}
void pin_direction(u8 port,u8 pin,u8 state)
{
	if (state==output)
	{
		SET_BIN((*(volatile u8*)(port+1)),pin);
	}
	else if(state==input)
	{
		RESET_BIN((*(volatile u8*)(port+1)),pin);
	}
}
void port_write(u8 port,u8 value)
{
	if(value==1)
	{
		*(volatile u8 *)(port+2)=0xff;
	}
	else if(value==0)
	{
		*(volatile u8*)(port+2)=0x00;
	}
	else
	{
		*(volatile u8*)(port+2)=value;
	}
}
void pin_write(u8 port,u8 pin,u8 value)
{
if(value==1)
	{
	SET_BIN((*(volatile u8*)(port+2)),pin);
	}
	else if(value==0)
	{
		RESET_BIN((*(volatile u8*)(port+2)),pin);
	}

}
u8 port_read(void* port)
{
u8 reading ;
reading=(*(volatile u8 *)(port));
return reading;}



u8 pin_read(u8 	port,u8 pin)
{
	u8 reading;
	reading= GETBIT((*(volatile u8 *)(port)),pin);
return reading;
}

