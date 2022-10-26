/*
 * STD_TYPES.h
 *
 *  Created on: Aug 15, 2022
 *      Author: Ibrahim
 */

#ifndef LIB_STD_TYPES_H_
#define LIB_STD_TYPES_H_


/*
 * Signed Data Types
 */
typedef unsigned char           u8;
typedef unsigned short int      u16;
typedef unsigned long int       u32;

/*
 * Unsigned Data Types
 */
typedef signed char             s8;
typedef signed short int        s16;
typedef signed long int         s32;

/*
 * Floating point Types
 */
typedef float                   f32;
typedef double                  f64;

/*
 * Address NULL
 */
#define ADDRESS_NULL ( (void *) 0x00)




typedef void (*Ptr_func_IvOv_t)(void);



#endif /* LIB_STD_TYPES_H_ */
