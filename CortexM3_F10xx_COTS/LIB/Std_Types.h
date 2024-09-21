/*
 * Std_Types.h
 *
 *  Created on: Sep 11, 2024
 *      Author: Ahmed Osama
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#define SET_BIT(REG, BIT)   				((REG) |= (1<<BIT))
#define CLEAR_BIT(REG, BIT)  				((REG) &=~(1<<BIT))
#define READ_BIT(REG, BIT)   				((REG) &(1<<BIT))
#define TOGGLE_BIT(REG,BIT) 				((REG) ^= (1<<BIT))

#define READ_REG(REG)						((REG))
#define WRITE_REG(REG,VAL)					((REG) =(VAL))
#define MODIFY_REG(REG,CLEARMASK,SETMASK)	WRITE_REG((REG) ,((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK))

#ifndef FALSE
#define FALSE       (0u)
#endif

#ifndef TRUE
#define TRUE        (1u)
#endif

#ifndef DISABLED
#define DISABLED    (0u)
#endif

#ifndef ENABLED
#define ENABLED     (1u)
#endif

#ifndef NULL
#define NULL        ((void*)0)
#endif

typedef unsigned char       uint8_t   	;       /*                    0 .. 255                   */
typedef signed char         int8_t    	;       /*                 -128 .. +127                  */
typedef unsigned short      uint16_t  	;       /*                    0 .. 65535                 */
typedef signed short        int16_t   	;       /*               -32768 .. +32767                */
typedef unsigned long       uint32_t  	;       /*                    0 .. 4294967295            */
typedef signed long         int32_t   	;       /*          -2147483648 .. +2147483647           */
typedef unsigned long long  uint64_t 	;       /*                    0 .. 18446744073709551615  */
typedef signed long long    int64_t   	;       /* -9223372036854775808 .. 9223372036854775807   */
typedef float               float32		;
typedef double              float64 	;


typedef enum
{
	OK				= 0x00U,
	ERROR			= 0x01U,
	NULL_PTR		= 0x02U,
	BUSY    		= 0x03U,
	TIMEOUT 		= 0x04U,
}ErrorStatus_t;


#endif /* STD_TYPES_H_ */
