/*
 * lib.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: KAREEM
 */

#ifndef LIB_H_
#define LIB_H_
#define F_CPU 8000000
#define SET_BIN(reg,bit) reg|=(1<<bit);
#define RESET_BIN(reg,bit) reg&=~(1<<bit)
#define TOGGLE_BIN(reg,bit) reg^=(1<<bit)
//#define GETBIT(number,bit_number) ((number&1<<bit_number)>>bit_number)
#define GETBIT(number,bit_number) ((number>>bit_number)&1)



#endif /* LIB_H_ */
