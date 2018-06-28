/*
 * typedefs.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: KAREEM
 */

#ifndef TYPEDEFS_H_
#define TYPEDEFS_H_




typedef unsigned short int u16;
typedef signed short int s16;
typedef unsigned long int u32;
typedef signed long int s32;
typedef signed char s8;
typedef unsigned char u8;
typedef float f32;
typedef double f64;
typedef long double f80;
typedef unsigned char*  pu8;
typedef unsigned short int*  pu16;
typedef struct
		{
	u16 first_delay;
	u16	periodicity;
	void (*ptrfun) (void);
		}task_type;






#endif /* TYPEDEFS_H_ */
