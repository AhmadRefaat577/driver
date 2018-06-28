/*
 * Macros.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Eng Mohamed Hamdy
 */

#ifndef MACROS_H_
#define MACROS_H_


#define SET_BIT(Byte,Pos)           (Byte |=(1<<Pos))
#define CLEAR_BIT(Byte,Pos)         (Byte &=~(1<<Pos))
#define TOGGLE_BIT(Byte,Pos)        (Byte ^=(1<<Pos))
#define GET_BIT(Reg,Bit)            ((Reg >>Bit)&1)    //(Reg &(1<<Bit))>>Bit

#define SET_BYTE(Byte)              (Byte |=(0xFF))
#define CLEAR_BYTE(Byte)            (Byte &=(0x00))

#define SET_NIBBLE_HIGH(Byte)       (Byte |=(0xF0))
#define SET_NIBBLE_LOW(Byte)        (Byte |=(0x0F))

#define CLEAR_NIBBLE_HIGH(Byte)     (Byte &=(0x0F))
#define CLEAR_NIBBLE_LOW(Byte)      (Byte &=(0xF0))


#endif /* MACROS_H_ */
